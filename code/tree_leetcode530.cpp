/*
 * @Author: Jean_Leung
 * @Date: 2024-10-06 22:33:27
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-06 23:57:41
 * @FilePath: \code\tree_leetcode530.cpp
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
    // int res; // 结果值
    int min_abs_difference = INT_MAX;
    vector<int> ans;
    int getMinimumDifference(TreeNode *root) {
        // 找出二叉搜索树中绝对值差最小的值
        // 思路一: 直接设置结果值
        // 直接前序递归
        if (root == NULL) {
            return 0;
        }
        // 在中序遍历的数组中找到最小差值
        for (int i = 1; i < ans.size(); i++) {
            min_abs_difference =
                min(min_abs_difference, abs(ans[i] - ans[i - 1]));
        }
        return min_abs_difference;
    }

    void inorder(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        // 左
        inorder(root->left);
        // 中
        ans.push_back(root->val);
        inorder(root->right);
    }

    TreeNode *pre = NULL; // 记录前一个节点
    int res = INT_MAX;
    int getMinimumDifference(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        dfs(root);
        return res;
    }
    // 中序递归法
    void dfs(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        // 左
        dfs(root->left);
        // 中
        if (pre != NULL) {
            res = min(res, abs(pre->val - root->val));
        }
        // 记录前一个
        pre = root;
        // 右
        dfs(root->right);
    }
};