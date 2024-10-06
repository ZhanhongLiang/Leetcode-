/*
 * @Author: Jean_Leung
 * @Date: 2024-10-02 22:46:18
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-02 23:27:20
 * @FilePath: \code\tree_leetcode617.cpp
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
    // 将两棵树进行合并,如果重叠的节点就进行加和,如果不重叠，那么直接覆盖
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (root1 == NULL && root2 == NULL) {
            return NULL;
        }
        if (root1 == NULL && root2 != NULL) {
            return root2;
        }
        if (root1 != NULL && root2 == NULL) {
            return root1;
        }
        return dfs(root1, root2);
    }

    // 需要同时对两颗树进行递归
    TreeNode *dfs(TreeNode *root1, TreeNode *root2) {
        // 如果同时两个节点为空则返回
        if (root1 == NULL && root2 == NULL) {
            return NULL;
        }
        // 终止条件
        if (root1 == NULL) {
            return root2;
        }
        if (root2 == NULL) {
            return root1;
        }
        auto root = new TreeNode(0);
        root->val = root1->val + root2->val;
        root->left = dfs(root1->left, root2->left);
        root->right = dfs(root1->right, root2->right);
        return root;
    }

    // // 迭代法??
    // // 必然可以用迭代法的，因为都能用前序递归了
    // // 那么使用BFS还是DFS的迭代呢??
    // // 如果我们考虑用DFS的迭代,那么就会出现一个问题怎么让访问的两个节点同时访问到
    // // 我们尝试一下前序遍历的迭代法
    // TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    //     if (root1 == NULL && root2 == NULL) {
    //         return NULL;
    //     }
    //     if (root1 == NULL && root2 != NULL) {
    //         return root2;
    //     }
    //     if (root1 != NULL && root2 == NULL) {
    //         return root1;
    //     }
    //     // 需要设置两个栈
    //     stack<TreeNode *> tree1_stack;
    //     stack<TreeNode *> tree2_stack;
    //     TreeNode *root = new TreeNode();
    //     tree1_stack.push(root1);
    //     tree2_stack.push(root2);
    //     while (!tree1_stack.empty() || !tree2_stack.empty()) {
    //         TreeNode* cur1 = tree1_stack.top();
    //         TreeNode* cur2 = tree2_stack.top();
    //         if(cur1 != NULL || cur2 != NULL){
    //             // 需要区分开到底是那个不为空
    //             if(cur1 != NULL && cur2 == NULL){
    //                 tree1_stack.pop(); // 出栈
    //             }
    //         }
    //     }
    // }
};