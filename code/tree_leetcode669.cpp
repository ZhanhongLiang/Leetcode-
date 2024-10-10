/*
 * @Author: Jean_Leung
 * @Date: 2024-10-09 09:37:29
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-09 11:09:50
 * @FilePath: \code\tree_leetcode669.cpp
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
    TreeNode *trimBST(TreeNode *root, int low, int high) {
        if (root == NULL) {
            return NULL;
        }
        return dfs(root, low, high);
    }

    // 还是通过递归实现
    // 想的太复杂
    TreeNode *dfs(TreeNode *&root, int low, int high) {
        if (root == NULL) {
            return NULL;
        }
        // 如果是小于low
        if (root->val < low) {
            return dfs(root->right, low, high);
        }
        // 如果是大于high
        if (root->val > high) {
            return dfs(root->left, low, high);
        }
        // 这里不是O(h),因为都要遍历寻找,并不用加if来判断
        root->left = dfs(root->left, low, high);
        root->right = dfs(root->right, low, high);
        return root;
    }

    // // 迭代法
    // TreeNode *trimBST(TreeNode *root, int low, int high) {
    //     if (root == NULL) {
    //         return NULL;
    //     }
    //     TreeNode *cur = root;
    //     TreeNode *pre = NULL; // 前一个结点接住
    //     //pre是cur的前一个父亲结点
    //     while(cur != NULL){
    //         // 当前节点小于low的时候
    //         if(cur->val < low && pre != NULL){
    //             // 直接将cur->right保存,将cur和cur->left删除
    //             // 
    //         }
    //     }
    // }
};