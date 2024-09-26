/*
 * @Author: Jean_Leung
 * @Date: 2024-09-26 13:20:10
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-26 13:38:42
 * @FilePath: \code\tree_leetcode116.cpp
 * @Description:
 *
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
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
  public:
    Node *connect(Node *root) {
        queue<Node *> tree_stack;
        if (root == NULL) {
            return root;
        }
        tree_stack.push(root);
        while (!tree_stack.empty()) {
            int size = tree_stack.size();
            for (int i = 0; i < size; i++) {
                Node *cur = tree_stack.front();
                tree_stack.pop();
                if (i < size - 1) {
                    cur->next = tree_stack.front();
                } else {
                    cur->next = NULL;
                }
                if (cur->left) {
                    tree_stack.push(cur->left);
                }
                if (cur->right) {
                    tree_stack.push(cur->right);
                }
            }
        }
        return root;
    }
};