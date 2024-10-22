/*
 * @Author: Jean_Leung
 * @Date: 2024-10-22 15:31:14
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-22 15:54:28
 * @FilePath: \code\dp_leetcode122.cpp
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
    int maxProfit(vector<int> &prices) {
        // 动态规划
        // dp[i][0]代表第i天持有股票的现金持有量
        // dp[i][1]代表第i天不持有股票的所得的现金持有量
        // max{前一天持有股票的现金,前一天不持有股票现金 - 当前买入的股票价格}
        // dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i])
        // max{前一天不持有股票的现金, 前一天持有股票现金 + 当前卖出的股票价格}
        // dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i])
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2));
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[prices.size() - 1][1];
    }
};