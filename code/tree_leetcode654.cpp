/*
 * @Author: Jean_Leung
 * @Date: 2024-10-02 21:47:52
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-02 22:43:41
 * @FilePath: \code\tree_leetcode654.cpp
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
    // 这道题就是二叉搜索树的变异版本
    // 建议将这道题和大根堆作为比较,到底和大根堆有什么区别???
    unordered_map<int, int> hash_map;
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            hash_map[nums[i]] = i;
        }
        return build(nums,0,nums.size()-1);
    }
    // 需要像快排那个样子吗??
    // 找最大值作为基准
    // 需要O(1),查询到最大值,所以需要哈希表
    TreeNode *build(vector<int> &nums, int left, int right) {
        if (left > right) {
            return NULL;
        }
        int max_value = INT_MIN;
        // 找最大值,如何做到O(1),答案没有,只能O(N)
        for (int i = left; i <= right; i++) {
            if (nums[i] > max_value) {
                max_value = nums[i];
            }
        }
        int k = hash_map[max_value]; // 找到最大值的下标
        auto root = new TreeNode(max_value); // 中
        root->left = build(nums, left, k - 1); // 左 
        root->right = build(nums, k + 1, right); // 右
        return root;
    }
};