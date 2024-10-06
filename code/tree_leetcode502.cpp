/*
 * @Author: Jean_Leung
 * @Date: 2024-10-07 02:05:19
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-07 02:31:52
 * @FilePath: \code\tree_leetcode502.cpp
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
    vector<int> res;
    vector<int> findMode(TreeNode *root) {
        if (root == NULL) {
            return res;
        }
        inorder(root);
        // 得到res数组
        unordered_map<int, int> hash_map;
        for (auto x : res) {
            hash_map[x]++;
        }
        vector<int> ans;
        // 找出哈希表中频率最多的数
        // 找出哈希表中频率最高的数
        int count = 0;
        for (const auto &x : hash_map) {
            if (x.second > count) {
                count = x.second;
            }
        }
        for (const auto &x : hash_map) {
            if (x.second == count) {
                ans.push_back(x.first);
            }
        }
        return ans;
    }

    // 法一,先中序遍历成数组
    // 然后哈希表进行记录频率
    // 最后输出

    void inorder(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        // 左
        inorder(root->left);
        // 中
        res.push_back(root->val);
        // 右
        inorder(root->right);
    }

    // 法2:使用中序遍历??
    // vector<pair<int, int>> res;
    // 这类题目最适合用哈希表
    // 遍历每个节点的时候直接假如哈希表
    unordered_map<int, int> hash_map;
    void dfs(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        // 左
        dfs(root->left);
        // 中
        hash_map[root->val]++;
        dfs(root->right);
    }

    vector<int> findMode(TreeNode *root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        dfs(root);
        // 找出哈希表中频率最多的数
        // 找出哈希表中频率最高的数
        int count = 0;
        for (const auto &x : hash_map) {
            if (x.second > count) {
                count = x.second;
            }
        }
        for (const auto &x : hash_map) {
            if (x.second == count) {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};