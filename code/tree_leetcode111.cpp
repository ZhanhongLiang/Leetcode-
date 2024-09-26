/*
 * @Author: Jean_Leung
 * @Date: 2024-09-26 14:01:46
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-26 14:25:45
 * @FilePath: \code\tree_leetcode111.cpp
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
    int minDepth(TreeNode *root) {
        queue<TreeNode *> tree_queue;
        int ans = 0;
        if (root == NULL) {
            return ans;
        }
        tree_queue.push(root);
        while (!tree_queue.empty()) {
            int size = tree_queue.size();
            ans++;
            for (int i = 0; i < size; i++) {
                TreeNode *cur = tree_queue.front();
                tree_queue.pop();
                if (cur->left) {
                    tree_queue.push(cur->left);
                }
                if (cur->right) {
                    tree_queue.push(cur->right);
                }
                if (cur->left == NULL && cur->right == NULL) {
                    return ans;
                }
            }
        }
        return ans;
    }
};