/*
 * @Author: Jean_Leung
 * @Date: 2024-10-08 11:11:55
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-10 13:15:33
 * @FilePath: \code\tree_leetcode450.cpp
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
    // 先递归思想
    // 想一下怎么才能删除二叉树
    // 分三种情况讨论:
    //         1.删除的节点是叶子节点，直接删除即可
    //         2.删除的节点有左子树或者右子树，将其子树替代删除节点即可
    //         3.删除的节点同时有左子树和右子树,找到其后继节点(其右子树中最左的节点),将其替代该节点即可
    //             然后删除最左侧的节点

    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == NULL) {
            return NULL;
        }
        delNode(root, key);
        return root;
    }

    void delNode(TreeNode *&root, int key) {
        if (root == NULL) {
            return;
        }
        // 找到要删除的节点
        if (root->val == key) {
            // 如果删除节点是叶子
            if (root->left == NULL && root->right == NULL) {
                root = NULL;
            } else if (root->right == NULL) {
                root = root->left;
            } else if (root->left == NULL) {
                root = root->right;
            } else {
                // 删除的节点是左右子树都有
                TreeNode *cur = root->right;
                while (cur->left) {
                    cur = cur->left;
                }
                // 替换
                root->val = cur->val;
                delNode(root->right, cur->val);
            }
        } else if (root->val > key) {
            delNode(root->left, key);
        } else {
            delNode(root->right, key);
        }
    }
};