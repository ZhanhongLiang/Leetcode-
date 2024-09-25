/*
 * @Author: Jean_Leung
 * @Date: 2024-09-25 14:46:50
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-25 15:08:56
 * @FilePath: \code\tree_leetcode429.cpp
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
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> result; // 答案数组
        // 层序遍历使用的是队列
        queue<Node *> tree_queue; // 队列结点
        // 需要设置每层的宽度进行遍历
        if (root != NULL) {
            tree_queue.push(root);
        }
        // 队列里面判断是否为空
        while (!tree_queue.empty()) {
            int size = tree_queue.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                Node *temp = tree_queue.front();
                tree_queue.pop();
                // 再继续遍历
                vec.push_back(temp->val);
                for (auto x : temp->children) {
                    if (x) {
                        tree_queue.push(x);
                    }
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};