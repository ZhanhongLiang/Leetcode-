/*
 * @Author: Jean_Leung
 * @Date: 2024-09-26 13:11:50
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-26 13:19:05
 * @FilePath: \code\tree_leetcode515.cpp
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
    vector<int> largestValues(TreeNode *root) {
        vector<int> result;
        queue<TreeNode *> tree_queue;
        if (root == NULL) {
            return result;
        }
        tree_queue.push(root);
        while (!tree_queue.empty()) {
            int size = tree_queue.size();
            // 找出每层最大的数
            int max_value = INT_MIN;
            for (int i = 0; i < size; i++) {
                TreeNode *cur = tree_queue.front();
                tree_queue.pop();
                max_value = max(max_value, cur->val);
                if (cur->left) {
                    tree_queue.push(cur->left);
                }
                if (cur->right) {
                    tree_queue.push(cur->right);
                }
            }
            result.push_back(max_value);
        }
        return result;
    }
};