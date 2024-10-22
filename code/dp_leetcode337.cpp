/*
 * @Author: Jean_Leung
 * @Date: 2024-10-22 11:55:24
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-22 14:24:28
 * @FilePath: \code\dp_leetcode337.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;
/**
 *  DP五部曲:
 *  1. 确定dp数组（dp table）以及下标的含义
    2. 确定递推公式
    3. dp数组如何初始化
    4. 确定遍历顺序
    5. 举例推导dp数组
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

// 树形DP,这道题可以作为模板题参考
class Solution {
  public:
    int rob(TreeNode *root) {
      vector<int> dp = robTreePostOrder(root);
      return max(dp[0],dp[1]);
    }

    // 0:不取当前节点时候的最大值
    // 1: 取当前节点时候的最大值
    vector<int> robTreePostOrder(TreeNode *root) {
        // 后序遍历
        // 后序遍历终止条件
        if (root == NULL) {
            return {0, 0};
        }
        // 左
        vector<int> left_value = robTreePostOrder(root->left);
        vector<int> right_value = robTreePostOrder(root->right);
        // 中
        // 取当前节点
        int value1 = root->val + left_value[0] + right_value[0];
        // 不取当前节点
        // 不取当前节点代表可以取左右子树的节点,或者不取左右子树的节点
        int value2 = max(left_value[0],left_value[1]) + max(right_value[0],right_value[1]);
        return {value2, value1};
    }
};