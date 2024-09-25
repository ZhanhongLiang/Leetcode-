/*
 * @Author: Jean_Leung
 * @Date: 2024-09-25 13:57:44
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-25 14:17:11
 * @FilePath: \code\tree_leetcode102.cpp
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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result; // 答案数组
        // 层序遍历使用的是队列
        queue<TreeNode *> tree_queue; // 队列结点
        // 需要设置每层的宽度进行遍历
        if (root != NULL) {
            tree_queue.push(root);
        }
        // 队列里面判断是否为空
        while (!tree_queue.empty()) {
            // 队列中size设置一下
            int size = tree_queue.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                // 先访问当前结点，且压入当前结点的左结点和右结点
                TreeNode *temp = tree_queue.front();
                tree_queue.pop();
                vec.push_back(temp->val);
                if (temp->left) {
                    tree_queue.push(temp->left);
                }
                if (temp->right) {
                    tree_queue.push(temp->right);
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};