/*
 * @Author: Jean_Leung
 * @Date: 2024-09-25 11:14:38
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-26 13:09:57
 * @FilePath: \code\tree_leetcode94.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
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
    // 因为需要前序遍历
    void traversal(TreeNode *cur, vector<int> &vec) {
        if (cur == NULL) {
            return;
        }
        traversal(cur->left, vec);  // 左
        vec.push_back(cur->val);    // 中
        traversal(cur->right, vec); // 右
    }
    vector<int> inorderTraversal(TreeNode *root) {
        // 前序遍历
        // 递归出口
        vector<int> result;
        traversal(root, result);
        return result;
    }
    // 非统一写法的迭代法
    vector<int> inorderTraversalII(TreeNode *root) {
        // 设置结点栈
        stack<TreeNode *> tree_stack;
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        TreeNode *cur = root;
        while (cur != NULL || !tree_stack.empty()) {
            // 如果压入栈是空的
            // 左中右
            if (cur != NULL) {
                tree_stack.push(cur);
                cur = cur->left;
            } else {
                // 如果是空的，那么就需要弹出当前的结点
                cur = tree_stack.top();
                tree_stack.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
    // 统一的迭代方法
    vector<int> inorderTraversalIII(TreeNode *root) {
        stack<TreeNode *> tree_stack;
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        tree_stack.push(root);
        while (!tree_stack.empty()) {
            TreeNode *cur = tree_stack.top();
            if (cur != NULL) {
                tree_stack.pop();
                if (cur->right) {
                    tree_stack.push(cur->right);
                }
                tree_stack.push(cur);
                tree_stack.push(NULL);
                if (cur->left) {
                    tree_stack.push(cur->left);
                }
            } else {
                tree_stack.pop();
                TreeNode *temp = tree_stack.top();
                tree_stack.pop();
                result.push_back(temp->val);
            }
        }
        return result;
    }
};