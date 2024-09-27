/*
 * @Author: Jean_Leung
 * @Date: 2024-09-27 15:47:49
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-27 16:17:09
 * @FilePath: \code\tree_leetcode599.cpp
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

// N叉树
class Node {
  public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
  public:
    // 层序遍历迭代法
    int maxDepth(Node *root) {
        // 层序遍历迭代法
        // int result = 0;
        int depth = 0;
        if (root == NULL) {
            return depth;
        }
        queue<Node *> tree_queue;
        tree_queue.push(root);
        while (!tree_queue.empty()) {
            int size = tree_queue.size();
            depth++;
            for (int i = 0; i < size; i++) {
                Node *temp = tree_queue.front();
                tree_queue.pop();
                for (auto x : temp->children) {
                    if (x != NULL) {
                        tree_queue.push(x);
                    }
                }
            }
            // result = max(result, depth);
        }
        return depth;
    }

    // 后序遍历递归法
    // 递归三部曲谨记: 1.确认递归的入参和返参 2.确认递归的终止条件 3.确认单层的递归逻辑
    // 入参为Node* root, 返参为int
    int getDepth(Node *root) {
        // 确认递归终止条件
        if (root == NULL) {
            return 0;
        }
        int depth = 0;
        // 单层递归逻辑左右中
        for (auto x : root->children) {
            depth = max(depth, getDepth(x));
        }
        return depth + 1; // 中
    }
    int maxDepthII(Node *root) { return getDepth(root); }
};