/*
 * @Author: Jean_Leung
 * @Date: 2024-10-09 12:58:24
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-09 13:23:36
 * @FilePath: \code\tree_leetcdoe538.cpp
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
    // 累加树（Greater Sum Tree 或 Accumulation Tree）是一个二叉树变种，
    // 它通常基于二叉搜索树（BST）来进行转换。
    // 累加树的特点是：对于每个节点，
    // 它的值被更新为原树中所有大于或等于该节点值的节点值的总和。
    TreeNode *convertBST(TreeNode *root) {
        // 思路: 通过反向的中序遍历: 右根左,也就是从大到小开始遍历
        if (root == NULL) {
            return NULL;
        }
        int sum = 0;
        dfs(root, sum);
        return root;
    }

    void dfs(TreeNode *root, int &sum) {
        // 反向中序遍历
        if (root == NULL) {
            return;
        }
        dfs(root->right, sum);
        sum += root->val;
        root->val = sum;
        dfs(root->left, sum);
    }

    // 中序遍历迭代法
    TreeNode *convertBST(TreeNode *root) {
        if (root == NULL) {
            return NULL;
        }
        stack<TreeNode *> tree_stack;
        int sum = 0;
        tree_stack.push(root);
        while (!tree_stack.empty()) {
            TreeNode *cur = tree_stack.top();
            if (cur != NULL) {
                tree_stack.pop(); // 先出栈
                // 先左入栈
                if (cur->left) {
                    tree_stack.push(cur->left);
                }
                tree_stack.push(cur);
                tree_stack.push(NULL);
                if (cur->right) {
                    tree_stack.push(cur->right);
                }
            } else {
                tree_stack.pop();
                TreeNode *temp = tree_stack.top();
                sum += temp->val;
                temp->val = sum;
                tree_stack.pop();
            }
        }
        return root;
    }
};