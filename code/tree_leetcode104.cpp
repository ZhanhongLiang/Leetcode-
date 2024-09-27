/*
 * @Author: Jean_Leung
 * @Date: 2024-09-26 13:56:03
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-27 15:45:23
 * @FilePath: \code\tree_leetcode104.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

// 二叉树的层序遍历
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
  public:
    int maxDepth(TreeNode *root) {
        queue<TreeNode *> tree_queue;
        int ans = 0;
        if (root == NULL) {
            return ans;
        }
        tree_queue.push(root);
        while (!tree_queue.empty()) {
            int size = tree_queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode *cur = tree_queue.front();
                tree_queue.pop();
                if (cur->left) {
                    tree_queue.push(cur->left);
                }
                if (cur->right) {
                    tree_queue.push(cur->right);
                }
            }
            ans++;
        }
        return ans;
    }

    // 后序遍历递归法
    int getDepth(TreeNode *root) {
        // 求参数统一用后序遍历
        // 因为求解的是高度,所以返回int类型
        // 传入的参数应该是遍历的结点
        // 终止条件:因为是求解高度，肯定是遇到叶子结点就结束遍历
        if (root == NULL) {
            return 0; // 递归返回
        }
        // 单层递归逻辑分析:
        // 返回的是根结点的高度,需要用后序遍历,求解参数基本后序遍历
        int left_depth = getDepth(root->left);
        int right_depth = getDepth(root->right);
        int depth = 1 + max(left_depth, right_depth); // 当前一层
        return depth;
    }
    // 后序遍历递归
    int maxDepthII(TreeNode *root) {
        // 递归法怎么做?
        // 递归三部曲
        // 确定递归函数的参数和返回参数
        // 确定递归的终止条件
        // 确定单层递归的逻辑
        // 本题是求二叉树的最大深度->也就是求根结点的高度
        // 某个结点高度的定义就是某个结点到叶子结点的最长简单路径边的条数或者结点数
        return getDepth(root);
    }
    // 前序遍历递归,比较难,不太会想到
    int result; // 因为是需要让整个递归都是共用同一个参数，需要定义类参数
    void getdepthII(TreeNode *node, int depth) {
        // 中左右
        result = depth > result ? depth : result; // 中
        // 递归出口
        if (node->left == NULL && node->right == NULL) {
            return;
        }
        // 单层递归逻辑
        if (node->left) {
            depth++;                       // 深度+1
            getdepthII(node->left, depth); // 进入递归
            depth--;                       // 回溯，深度-1;
        }
        if (node->right) {
            depth++;
            getdepthII(node->right, depth);
            depth--;
        }
        return;
    }
    // 前序遍历.
    int maxDepthIII(TreeNode *root) {
        result = 0;
        if (root == NULL)
            return result;
        getdepthII(root, 1);
        return result;
    }
};