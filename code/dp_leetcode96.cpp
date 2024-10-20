/*
 * @Author: Jean_Leung
 * @Date: 2024-10-20 12:57:17
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-20 13:33:47
 * @FilePath: \code\dp_leetcode96.cpp
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
class Solution {
  public:
    int numTrees(int n) {
        // dp[i] += dp[j - 1]* dp[i - j];
        // dp[i]为从1到i的不同二叉搜索树的个数
        // dp[j - 1]是以j为头节点，其左子树不同二叉搜索树的个数
        // dp[i - j]是以j为头节点,其右子树不同二叉树的个数
        // 初始化,将dp[0]初始化为1,因为但0为节点时候,空集也是一种二叉搜索树
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};