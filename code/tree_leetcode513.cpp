/*
 * @Author: Jean_Leung
 * @Date: 2024-09-29 11:22:34
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-30 10:44:35
 * @FilePath: \code\tree_leetcode513.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <math.h>
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

// class DepthNode {
//   public:
//     int depth; // 记录每个结点的深度
//     DepthNode() {}
//     DepthNode(int depth_) { depth = depth_; }
// };

class Solution {
  public:
    // 找出二叉树最底层中最左面的节点的值
    // 注意: 并非一定是叶子节点,因为这个节点可能是存在右子树
    // 所以根据这道题,我们需要记录深度,且需要是最左边

    // 因为是求解的是最深的一行
    // 采用前序遍历
    int result = 0;          // 记录最大深度中最左边的值
    int max_depth = INT_MIN; // 记录最大深度
    void findMaxDepthLeftNode(TreeNode *root, int depth) {
        // 如果当遇到叶子结点的时候，需要统计一下最大深度
        // 且更新最大深度
        if (depth > max_depth) {
            max_depth = depth;
            result = root->val; // 结果值保存
        }
        // 递归需要回溯算法
        if (root->left) {
            depth++;
            findMaxDepthLeftNode(root->left, depth);
            depth--;
        }
        if (root->right) {
            depth++;
            findMaxDepthLeftNode(root->right, depth);
            depth--;
        }
        return;
    }

    int findBottomLeftValue(TreeNode *root) {
        findMaxDepthLeftNode(root, 0);
        return result;
    }

    // Y神前序遍历写法
    // 递归返回还是这个
    int result = 0;    // 记录最大深度中最左边的值
    int max_depth = 0; // 记录最大深度
    void dfs(TreeNode *root, int depth) {
        // 终止条件
        if (root == NULL) {
            return;
        }
        if (depth > max_depth) {
            max_depth = depth;
            result = root->val;
        }
        // 先左侧,因为这里不是depth++,所以说是隐藏着回溯
        // dfs执行完之后退回上一层时候,depth是恢复到原来的元素
        dfs(root->left, depth + 1);  // 隐藏着回溯
        dfs(root->right, depth + 1); // 隐藏着回溯
    }

    int findBottomLeftValue(TreeNode *root) {
        dfs(root, 1);
        return result;
    }

    // 层序遍历,宽度搜索
    int findBottomLeftValue(TreeNode *root) {
        int ans = 0; // 记录返回结点值答案
        // int depth = 0; // 记录深度
        // int MAX_DEPTH = INT_MIN;
        // 层序遍历
        if (root == NULL) {
            return 0;
        }
        queue<TreeNode *> tree_queue;
        tree_queue.push(root); // 插入根结点
        while (!tree_queue.empty()) {
            TreeNode *temp = tree_queue.front(); // 记录队列头一个结点
            int size = tree_queue.size();
            // depth++; // 深度+1
            for (int i = 0; i < size; i++) {
                // 需要记录队列头一个结点，就是最左侧结点
                TreeNode *cur = tree_queue.front();
                tree_queue.pop();
                if (cur->left) {
                    tree_queue.push(cur->left);
                }
                if (cur->right) {
                    tree_queue.push(cur->right);
                }
            }
            // 判断以下是否是空的
            if (tree_queue.empty()) {
                ans = temp->val;
            }
        }
        return ans;
    }

    // // 写法三，后序遍历??

    // int findBottomLeftValue(TreeNode *root) {
    //     dfsII(root, 1);
    //     return result;
    // }

    // void dfsII(TreeNode *root, int depth) {

    // }
};