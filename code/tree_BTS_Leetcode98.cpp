/*
 * @Author: Jean_Leung
 * @Date: 2024-10-03 00:26:38
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-06 14:09:41
 * @FilePath: \code\tree_BTS_Leetcode98.cpp
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

struct BTSNode {
    TreeNode *root; // 存储当前节点
    bool is_BTS;
    int min_value; // 存储以当前节点为根节点的子树的最小值
    int max_value; // 存储以当前节点为根节点的子树最大值
    BTSNode()
        : root(NULL), is_BTS(false), min_value(INT_MAX), max_value(INT_MIN) {};
    BTSNode(TreeNode *node)
        : root(node), is_BTS(false), min_value(INT_MAX), max_value(INT_MIN) {};
    BTSNode(TreeNode *node, bool is_BTS_)
        : root(node), is_BTS(is_BTS_), min_value(INT_MAX),
          max_value(INT_MIN) {};
    BTSNode(TreeNode *node, bool is_BTS_, int min_)
        : root(node), is_BTS(is_BTS_), min_value(min_), max_value(INT_MIN) {};
    BTSNode(TreeNode *node, bool is_BTS_, int min_, int max_)
        : root(node), is_BTS(is_BTS_), min_value(min_), max_value(max_) {};
};

// 验证一颗树是否为二叉搜索树
class Solution {
  public:
    // 直接中序递归法
    // bool is_BTS = true;
    bool isValidBST(TreeNode *root) {
        if (root == NULL) {
            return false;
        }
        return dfs(root)->is_BTS;
    }

    BTSNode *dfs(TreeNode *root) {
        // // 根节点
        if (root == NULL) {
            return new BTSNode();
        }
        // 当前节点的状态
        BTSNode *res = new BTSNode(root, true, root->val, root->val);
        if (root->left) {
            auto t = dfs(root->left);
            if (!t->is_BTS || t->max_value >= root->val) {
                res->is_BTS = false;
            }
            res->max_value = max(t->max_value, res->max_value);
            res->min_value = min(t->min_value, res->min_value);
        }
        if (root->right) {
            auto t = dfs(root->right);
            if (!t->is_BTS || t->min_value <= root->val) {
                res->is_BTS = false;
            }
            res->max_value = max(t->max_value, res->max_value);
            res->min_value = min(t->min_value, res->min_value);
        }
        return res;
    }

    // 法2: 利用二叉搜索树的特性，中序遍历是有序的
    // 输出二叉搜索树的中序遍历数组
    // 设置vector
    vector<int> ans;
    bool isValidBST(TreeNode *root) {
        // 使用中序遍历
        inorder(root);
        // 判断数组是否是有序的
        for (int i = 1; i < ans.size(); i++) {
            // 如果存在前面的数大于后面的数，那么就返回false
            if (ans[i] <= ans[i - 1]) {
                return false;
            }
        }
        return true;
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

    // Y神写法
    // 前序递归遍历法
    vector<int> dfsII(TreeNode *root) {
        // vector<in>
        // 第一个数放这个节点的子树是否都是二叉搜索树
        // 第二个数是当前节点的子树中最小的值
        // 第三个数是当前节点的子树中最大的值
        // 保存当前节点的结果值
        vector<int> res({1, root->val, root->val});
        if (root->left) {
            auto t = dfsII(root->left);
            // 判断当前节点的左子树是否是二叉搜索树
            if (!t[0] || t[2] >= root->val) {
                res[0] = 0;
            }
            // 且找到最小和最大的值
            res[1] = min(t[1], res[1]);
            res[2] = max(t[2], res[2]);
        }
        if (root->right) {
            auto t = dfsII(root->right);
            if (!t[0] || t[1] <= root->val) {
                res[0] = 0;
            }
            // 且找到最小和最大的值
            res[1] = min(t[1], res[1]);
            res[2] = max(t[2], res[2]);
        }
        return res;
    }

    bool isValidBST(TreeNode *root) {
        if (root == NULL) {
            return false;
        }
        return dfsII(root)[0];
    }

    // 中序迭代法
    // 用一个per记录当前节点的前一个节点，按照左中右的顺序，必然是左在中前面
    // 所以pre保存的是左节点
    bool isValidBST(TreeNode *root) {
        if (root == NULL) {
            return false;
        }
        // 进行中序遍历
        TreeNode *pre = NULL;
        stack<TreeNode *> tree_stack;
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
                if (pre != NULL && temp->val <= pre->val) {
                    return false;
                }
                tree_stack.pop();
                pre = temp;
            }
        }
        return true;
    }
};