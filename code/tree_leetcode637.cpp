/*
 * @Author: Jean_Leung
 * @Date: 2024-09-25 14:42:36
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-25 14:44:11
 * @FilePath: \code\tree_leetcode637.cpp
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

class Solution {
  public:
    vector<double> averageOfLevels(TreeNode *root) {
        // 二叉树的右视图
        vector<double> result;
        queue<TreeNode *> tree_queue;
        if (root != NULL) {
            tree_queue.push(root);
        }
        // 遍历队列
        while (!tree_queue.empty()) {
            int size = tree_queue.size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode *temp = tree_queue.front();
                tree_queue.pop(); // 弹出栈
                sum += temp->val;
                if (temp->left) {
                    tree_queue.push(temp->left);
                }
                if (temp->right) {
                    tree_queue.push(temp->right);
                }
            }
            double ans = sum / size;
            result.push_back(ans);
        }
        return result;
    }
};