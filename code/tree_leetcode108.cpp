/*
 * @Author: Jean_Leung
 * @Date: 2024-10-09 11:44:31
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-09 11:54:10
 * @FilePath: \code\tree_leetcode108.cpp
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
    TreeNode *root = NULL;
    // 递归，每次从数组中的中间分出根节点,必然可以构建成平衡二叉搜索树
    // 数学证明: 需要证明左右子树是不大于 log2(n+1)向上取整
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        // 取中间
        return dfs(nums, 0, nums.size() - 1);
    }

    TreeNode *dfs(vector<int> &nums, int left, int right) {
        if (left < right) {
            return NULL;
        }
        int mid = (right - left) / 2 + left;
        // 找到中间节点
        auto p = new TreeNode(nums[mid]);
        // 然后根据中间节点进行递归
        p->left = dfs(nums, left, mid - 1);
        p->right = dfs(nums, mid + 1, right);
        return p;
    }
};