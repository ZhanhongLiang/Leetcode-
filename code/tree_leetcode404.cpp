/*
 * @Author: Jean_Leung
 * @Date: 2024-09-28 10:58:58
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-28 11:30:14
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
    // 求解性质，可以后序递归遍历直接秒杀

    // 确定入参和返参,因为这道题涉及回溯思想

    int getLeftSum(TreeNode *root) {
        // 中序遍历
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            return 0;
        }
        // 左
        int left_sum = getLeftSum(root->left);
        // 如果当前结点的符合有左叶子结点
        if (root->left != NULL && root->left->left == NULL &&
            root->left->right == NULL) {
            // return root->left->val;
            left_sum = root->left->val;
        }
        // 右
        int right_sum = getLeftSum(root->right);
        int sum = left_sum + right_sum;
        return sum;
    }

    int sumOfLeftLeaves(TreeNode *root) {
        int result = 0;
        if (root == NULL) {
            return 0;
        }
        result = getLeftSum(root);
        return result;
    }
};