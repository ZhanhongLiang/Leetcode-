/*
 * @Author: Jean_Leung
 * @Date: 2024-09-25 11:04:07
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-26 13:05:48
 * @FilePath: \code\tree_leetcode145.cpp
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
        traversal(cur->right, vec); // 右
        vec.push_back(cur->val);    // 中
    }
    vector<int> postorderTraversal(TreeNode *root) {
        // 前序遍历
        // 递归出口
        vector<int> result;
        traversal(root, result);
        return result;
    }
    // 后序遍历
    vector<int> postorderTraversalII(TreeNode *root) {
        // 后序遍历过程
        stack<TreeNode *> tree_stack; // 树结点栈
        // TreeNode *cur = root;         // 赋予根节点
        vector<int> result; // 结果集
        if (root == NULL) {
            return result;
        }
        tree_stack.push(root); // 栈
        while (!tree_stack.empty()) {
            // 栈顶
            TreeNode *temp = tree_stack.top();
            // 出栈
            tree_stack.pop();
            result.push_back(temp->val);
            if (temp->left) {
                // 压入左结点
                tree_stack.push(temp->left);
            }
            if (temp->right) {
                // 压入右结点
                tree_stack.push(temp->right);
            }
        }
        // 转化为左右中
        reverse(result.begin(), result.end());
        return result;
    }
    // 后序遍历操作
    vector<int> postorderTraversalIII(TreeNode *root) {
        // 后序遍历统一迭代的方法
        stack<TreeNode *> tree_stack;
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        tree_stack.push(root);
        while (!tree_stack.empty()) {
            TreeNode *cur = tree_stack.top();
            if (cur != NULL) {
                // tree_stack.pop();
                // tree_stack.push(cur);
                tree_stack.push(NULL);
                if (cur->right) {
                    tree_stack.push(cur->right);
                }
                if (cur->left) {
                    tree_stack.push(cur->left);
                }
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
