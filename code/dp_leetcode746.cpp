/*
 * @Author: Jean_Leung
 * @Date: 2024-10-19 13:42:31
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-19 13:57:24
 * @FilePath: \code\dp_leetcode746.cpp
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
    int minCostClimbingStairs(vector<int> &cost) {
        // dp[i]代表到达第i个台阶的最低消费
        // dp[i]是递增的
        // dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        int dp[cost.size() + 1];
        dp[0] = 0;
        dp[1] = 0;
        if (cost.size() <= 1) {
            return 0;
        }
        // int cost = 0; // 记录总消费
        for (int i = 2; i <= cost.size(); i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[cost.size()];
    }
};