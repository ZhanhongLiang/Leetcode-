/*
 * @Author: Jean_Leung
 * @Date: 2024-10-08 11:11:55
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-08 13:09:39
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
    // 参考Y神思路,Y神的思路基本都是最简洁的
    TreeNode *deleteNode(TreeNode *root, int key) {
        // 删除节点
        if (root == NULL) {
            return root;
        }
        del(root, key);
        return root;
    }
    // 传入的是root节点,是一个引用来到
    void del(TreeNode *&root, int key) {
        // 二叉搜索树的删除是需要分三种情况的
        // 叶子节点：直接删除，无需其他操作。
        // 一个子节点：用该子节点替换要删除的节点。
        // 两个子节点：用前驱或后继节点的值替换要删除的节点，并删除前驱或后继节点
        // 我们这道题先按照后继节点的方式来做
        // 如果当前节点是空节点
        if (root == NULL) {
            return;
        }
        if (key == root->val) {
            // 叶子节点
            if (root->left == NULL && root->right == NULL) {
                root = NULL; // 因为传入的是引用，是可以直接影响root的
            } else if (root->right == NULL) {
                // 一个叶子节点
                // 删除当前节点，然后用左子树替代其节点
                root = root->left;
            } else if (root->left == NULL) {
                // 一个叶子节点
                root = root->right;
            } else {
                // 递归找到其后继节点
                // 也就是当前右子树
                auto p = root->right;
                while (p->left != NULL) {
                    p = p->left;
                }
                root->val = p->val;
                del(root->right, p->val); // 直接递归在root->right里面删除p节点
            }
        } else if (root->val > key) {
            del(root->left, key);
        } else {
            del(root->right, key);
        }
    }

    // 迭代法
    // 这一步就是核心的思想
    // 还是分三种情况讨论
    TreeNode *delNode(TreeNode *node) {
        if (node == NULL) {
            return node;
        }
        // 如果当前结点是叶子结点则删除，且返回
        if (node->left == NULL && node->right == NULL) {
            return NULL;
        } else if (node->right == NULL) {
            return node->left;
        }
        // 找到当前结点的右子树中最小的点
        TreeNode *cur = node->right;
        while (cur->left) {
            cur = cur->left;
        }
        // 将当前找到的cur的左边变为node的左边
        cur->left = node->left;
        return node->right;
    }

    TreeNode *deleteNode(TreeNode *root, int key) {
        // 找到对应删除的节点
        if (root == NULL) {
            return root;
        }
        // 否则进行删除操作
        // 记录遍历工作节点
        TreeNode *cur = root;
        // 记录要删除节点的前一个父亲节点
        TreeNode *pre = NULL;
        while (cur != NULL) {
            // 当遍历的工作节点的值是key的时候
            if (cur->val == key) {
                break;
            }
            // 记录前一个结点
            pre = cur;
            if (cur->val > key) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }

        // 如果pre结点还是NULL的话
        // 证明没找到结点,返回root即可
        if (pre == NULL) {
            return delNode(cur);
        }
        // 否则是找到对应key的结点了
        // 这个时候对cur进行讨论
        if (pre->left && pre->left->val == key) {
            pre->left = delNode(cur);
        } else {
            pre->right = delNode(cur);
        }
        return root;
    }
};