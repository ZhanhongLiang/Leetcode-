/*
 * @Author: Jean_Leung
 * @Date: 2024-09-26 17:38:58
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-26 18:34:36
 * @FilePath: \code\tree_leetcode226.cpp
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

// 这道题直接将所有的遍历方式串联起来了
// 前序遍历递归+迭代法
// 后序遍历递归+迭代法
// 层序遍历法
class Solution {
  public:
    TreeNode *invertTree(TreeNode *root) {
        // 反转
        // 递归出口
        if (root == NULL) {
            return NULL;
        }
        // 先中
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    TreeNode *invertTreeI(TreeNode *root) {
        // 反转
        if (root == NULL) {
            return NULL;
        }
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }

    TreeNode *invertTreeIII(TreeNode *root) {
        // 反转
        stack<TreeNode *> tree_stack;
        if (root == NULL) {
            return root;
        }
        tree_stack.push(root);
        while (!tree_stack.empty()) {
            TreeNode *cur = tree_stack.top();
            if (cur != NULL) {
                // 假如栈顶元素不是空指针
                tree_stack.pop(); // 先弹出，防止重复操作
                if (cur->right) {
                    tree_stack.push(cur->right);
                }
                if (cur->left) {
                    tree_stack.push(cur->left);
                }
                tree_stack.push(cur);
                tree_stack.push(NULL);
            } else {
                tree_stack.pop();
                TreeNode *temp = tree_stack.top();
                tree_stack.pop();
                swap(temp->left, temp->right);
            }
        }
        return root;
    }

    TreeNode *invertTreeV(TreeNode *root) {
        // 后序遍历的迭代版本
        // 反转
        stack<TreeNode *> tree_stack;
        if (root == NULL) {
            return root;
        }
        tree_stack.push(root);
        while (!tree_stack.empty()) {
            TreeNode *cur = tree_stack.top();
            if (cur != NULL) {
                // 假如栈顶元素不是空指针
                tree_stack.push(NULL);
                if (cur->right) {
                    tree_stack.push(cur->right);
                }
                if (cur->left) {
                    tree_stack.push(cur->left);
                }
            } else {
                tree_stack.pop();
                TreeNode *temp = tree_stack.top();
                tree_stack.pop();
                swap(temp->left, temp->right);
            }
        }
        return root;
    }

    TreeNode *invertTreeVI(TreeNode *root) {
        // 层序遍历
        queue<TreeNode *> tree_queue;
        // int ans = 0;
        if (root == NULL) {
            return root;
        }
        tree_queue.push(root);
        while (!tree_queue.empty()) {
            int size = tree_queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode *cur = tree_queue.front();
                tree_queue.pop();
                swap(cur->left,cur->right);
                if (cur->left) {
                    tree_queue.push(cur->left);
                }
                if (cur->right) {
                    tree_queue.push(cur->right);
                }
            }
        }
        return root;
    }
};