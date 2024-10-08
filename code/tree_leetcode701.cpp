/*
 * @Author: Jean_Leung
 * @Date: 2024-10-07 21:25:42
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-08 11:10:45
 * @FilePath: \code\tree_leetcode701.cpp
 * @Description: 二叉搜索树的插入操作
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
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        // 二叉搜索树的插入操作
        if (root == NULL) {
            return new TreeNode(val);
        }
        dfs(root, val);
        return root;
    }
    TreeNode *pre = NULL; // 记录遍历时节点的前一个父节点
    void dfs(TreeNode *root, int val) {
        // 当前节点为空节点时候
        if (root == NULL) {
            TreeNode *temp = new TreeNode(val);
            if (pre->val > val) {
                pre->left = temp;
            } else {
                pre->right = temp;
            }
            return;
        }
        pre = root; // 记录上个节点
        // 二叉搜索树是选择性进入某个子树,所以需要if判断
        if (root->val > val) {
            dfs(root->left, val);
        }
        if (root->val < val) {
            dfs(root->right, val);
        }
        return;
    }

    // Y神代码
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (root == NULL) {
            // 当前节点是空的时候
            // 创建一个新的节点
            return new TreeNode(val);
        }
        // 如果当前节点大于val的话
        // 往左子树插入
        // 否则往右子树插入
        if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }

    // 迭代写法
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        // 不使用栈
        if (root == NULL) {
            return new TreeNode(val);
        }
        // 找到上一个结点
        TreeNode *pre_node = NULL;
        // 工作节点
        TreeNode *cur = root;
        while (cur != NULL) {
            pre_node = cur;
            if (cur->val > val) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
            if (cur == NULL) {
                // 前一个结点进行连接
                if (pre_node->val > val) {
                    pre_node->left = new TreeNode(val);
                } else {
                    pre_node->right = new TreeNode(val);
                }
            }
        }
        return root;
    }
};