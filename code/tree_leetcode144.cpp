/*
 * @Author: Jean_Leung
 * @Date: 2024-09-25 10:44:07
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-26 12:59:37
 * @FilePath: \code\tree_leetcode144.cpp
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
        vec.push_back(cur->val);    // 中
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
    }
    vector<int> preorderTraversal(TreeNode *root) {
        // 前序遍历
        // 递归出口
        vector<int> result;
        traversal(root, result);
        return result;
    }

    // 统一的迭代方法
    vector<int> preorderTraversalII(TreeNode *root) {
        stack<TreeNode *> tree_stack; // 设置节点栈
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        // 先将根节点压入栈中
        tree_stack.push(root);
        while (!tree_stack.empty()) {
            TreeNode *temp = tree_stack.top(); // 栈顶
            tree_stack.pop();
            result.push_back(temp->val);
            if (temp->right) {
                tree_stack.push(temp->right);
            }
            if (temp->left) {
                tree_stack.push(temp->left);
            }
        }
        return result;
    }

    // 统一的迭代方法
    vector<int> preorderTraversalIII(TreeNode *root) {
        // 设置栈
        stack<TreeNode *> tree_stack;
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        tree_stack.push(root);
        while (!tree_stack.empty()) {
            // 拿出栈顶元素
            TreeNode *cur = tree_stack.top();
            if (cur != NULL) {
                tree_stack.pop(); // 先出栈
                // 压入栈中
                if (cur->right) {
                    tree_stack.push(cur->right);
                }
                if (cur->left) {
                    tree_stack.push(cur->left);
                }
                tree_stack.push(cur);
                tree_stack.push(NULL);
            } else {
                // 先出空栈
                tree_stack.pop();
                TreeNode *temp = tree_stack.top();
                tree_stack.pop();
                result.push_back(temp->val);
            }
        }
        return result;
    }
};
