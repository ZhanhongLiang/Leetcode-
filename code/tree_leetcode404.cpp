/*
 * @Author: Jean_Leung
 * @Date: 2024-09-28 10:58:58
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-30 09:46:26
 * @FilePath: \code\tree_leetcode404.cpp
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
    // 求二叉树所有左叶子之和
    // 思路: 中序递归遍历
    // 法一:
    int getLeftSum(TreeNode *root) {
        // 确定入参和返参, 入参为root,返参为int,代表每个左叶子的值
        // 确定终止条件
        if (root == NULL) {
            return 0;
        }
        // 当结点为叶子结点但不是左叶子的时候终止
        if (root->left == NULL && root->right == NULL) {
            return 0;
        }
        // 左
        int left_sum = getLeftSum(root->left);
        // 中,如果当前结点是左叶子,则sum是
        if (root->left != NULL && root->left->left != NULL &&
            root->left->right == NULL) {
            left_sum = root->left->val;
        }
        // 右
        int right_sum = getLeftSum(root->right);
        // 等于左树+右树
        int sum = right_sum + left_sum;
        return sum;
    }
    int sumOfLeftLeaves(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        return getLeftSum(root);
    }

    // 法2:既然可以中序递归，那么必然可以中序迭代
    int sumOfLeftLeavesII(TreeNode *root) {
        int sum = 0;
        if (root == NULL) {
            return sum;
        }
        // 设定栈
        stack<TreeNode *> tree_stack;
        tree_stack.push(root);
        while (!tree_stack.empty()) {
            // 取出栈顶的结点
            TreeNode *cur = tree_stack.top();
            if (cur != NULL) {
                // 取出栈顶元素,防止重新入栈
                tree_stack.pop();
                // 入栈顺序为右 中 左
                // 右
                if (cur->right) {
                    tree_stack.push(cur->right);
                }
                // 中
                tree_stack.push(cur);
                tree_stack.push(NULL);
                // 左
                if (cur->left) {
                    tree_stack.push(cur->left);
                }
            } else {
                // 判断当前结点是否是左叶子结点
                tree_stack.pop();                  // 出空栈
                TreeNode *temp = tree_stack.top(); // 取出当前结点
                tree_stack.pop();
                // 判断当前结点是否是左叶子结点
                if (temp->left != NULL && temp->left->left == NULL &&
                    temp->left->right == NULL) {
                    sum += temp->left->val;
                }
            }
        }
        return sum;
    }
    // // 法3,因为可以使用中序遍历,那么理论上可以前序或者后序遍历
    // // 尝试后序递归遍历解决
    // int getLeftSumII(TreeNode *root) {
    //     // 是包含回溯思想？
    //     if (root == NULL) {
    //         return 0;
    //     }
    //     if (root->left == NULL && root->left == NULL) {
    //         return 0;
    //     }
    //     // 左
    //     int left_sum = getLeftSumII(root->left);
    //     // 右
    //     int right_sum = getLeftSumII(root->right);
    //     // 中, 如果当前结点为左叶子结点
    //     if(root->left != NULL && root->left->left == NULL && root->left->right == NULL){
    //         left_sum = root->left->val;
    //     }
    //     int sum = left_sum + right_sum;
    //     return sum;
    // }
};