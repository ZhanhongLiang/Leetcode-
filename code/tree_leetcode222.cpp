/*
 * @Author: Jean_Leung
 * @Date: 2024-09-27 17:16:28
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-27 17:29:02
 * @FilePath: \code\tree_leetcode222.cpp
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
    // 层序遍历迭代法
    int countNodes(TreeNode *root) {
        int count = 0;
        if (root == NULL) {
            return count;
        }
        queue<TreeNode *> tree_queue;
        tree_queue.push(root);
        while (!tree_queue.empty()) {
            int size = tree_queue.size();
            count += size;
            for (int i = 0; i < size; i++) {
                TreeNode *cur = tree_queue.front();
                tree_queue.pop();
                if (cur->left) {
                    tree_queue.push(cur->left);
                }
                if (cur->right) {
                    tree_queue.push(cur->right);
                }
            }
        }
        return count;
    }

    // 后序递归法
    int countNodesII(TreeNode *root) {
        // 确认终止条件
        if (root == NULL) {
            return 0;
        }
        // 单层递归逻辑
        int count_left = countNodesII(root->left);
        int count_right = countNodesII(root->right);
        int count = count_left + count_right + 1;
        // 返回该层的结点数
        return count;
    }
};