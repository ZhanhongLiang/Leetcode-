/*
 * @Author: Jean_Leung
 * @Date: 2024-10-02 23:34:46
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-03 00:27:03
 * @FilePath: \code\tree_BTS_leetcode700.cpp
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

class Solution {
  public:
    // 二叉搜索树就是左子树所有的节点都小于根节点,
    // 右子树所有的节点都大于根节点
    // 左子树和右子树都为二叉树搜索树
    // 二叉搜索树的中序递归是有序的,左中右,那就是递增的排序
    // 返回子树
    TreeNode *result = NULL;
    // TreeNode* result = new TreeNode();
    TreeNode *searchBST(TreeNode *root, int val) {
        // 这道题直接前序递归即可即可
        if (root == NULL) {
            return NULL;
        }
        // dfs(root, val);
        // 这个是筛选出特殊情况，就是当val != 0,且 返回的是初始化的result的时候
        // 那么就是代表找不到的特殊情况
        // 因为按照这个递归，如果不筛选这种情况，那么就可能出现val!=0，且返回result.val==0的情况
        // 这种时候返回result是错误的，不符合题意,因为我们按照题意应该是找不到的
        // if (val != 0 && result->val == 0 && result->left == NULL &&
        //     result->right == NULL) {
        //     return NULL;
        // }
        dfs(root, val);
        return result;
    }
    void dfs(TreeNode *root, int val) {
        // 终止条件
        if (root == NULL) {
            return;
        }
        // 中
        if (root->val == val) {
            result = root;
        }
        // 左
        if (root->val > val) {
            dfs(root->left, val);
        }
        // 右
        if (root->val < val) {
            dfs(root->right, val);
        }
        return;
    }

    // 代码随想录的写法
    TreeNode *searchBST(TreeNode *root, int val) {
        // 终止条件
        if (root == NULL || root->val == val) {
            return root;
        }
        TreeNode *ans = NULL;
        if (root->val > val) {
            ans = searchBST(root->left, val);
        }
        if (root->val < val) {
            ans = searchBST(root->right, val);
        }
        return ans;
    }

    // 迭代写法
    // 最简单理解的，因为二叉搜索树的有序性
    // 其中序遍历是递增有序的
    TreeNode *searchBST(TreeNode *root, int val) {
        if (root == NULL) {
            return NULL;
        }
        // 按照二叉搜索树的特性进行筛查
        // 也不用借助栈或者队列
        while (root != NULL) {
            if (root->val == val) {
                return root;
            }
            if (root->val > val) {
                root = root->left;
                continue;
            }
            if (root->val < val) {
                root = root->right;
                continue;
            }
        }
        return NULL;
    }
};