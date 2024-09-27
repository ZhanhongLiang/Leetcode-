/*
 * @Author: Jean_Leung
 * @Date: 2024-09-26 14:01:46
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-27 16:59:38
 * @FilePath: \code\tree_leetcode111.cpp
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
    // 层序迭代法
    int minDepth(TreeNode *root) {
        queue<TreeNode *> tree_queue;
        int ans = 0;
        if (root == NULL) {
            return ans;
        }
        tree_queue.push(root);
        while (!tree_queue.empty()) {
            int size = tree_queue.size();
            ans++;
            for (int i = 0; i < size; i++) {
                TreeNode *cur = tree_queue.front();
                tree_queue.pop();
                if (cur->left) {
                    tree_queue.push(cur->left);
                }
                if (cur->right) {
                    tree_queue.push(cur->right);
                }
                if (cur->left == NULL && cur->right == NULL) {
                    return ans;
                }
            }
        }
        return ans;
    }

    // 后序递归法
    int getDepth(TreeNode *root) {
        // 确认入参和返参
        // 确认递归终止条件
        // 因为是找到最小深度
        // 单层逻辑思考
        // 终止条件
        if (root == NULL) {
            return 0;
        }
        int left_depth = getDepth(root->left);
        int right_depth = getDepth(root->right);
        // 如果当左子树为空,右子树不为空
        if (root->left == NULL && root->right != NULL) {
            return 1 + right_depth;
        }
        // 如果当右子树为空,左子树不为空
        if (root->left != NULL && root->right == NULL) {
            return 1 + left_depth;
        }
        int depth = 1 + min(left_depth, right_depth);
        return depth;
    }
    int minDepthII(TreeNode *root) { return getDepth(root); }
};
