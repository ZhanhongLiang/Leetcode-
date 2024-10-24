/*
 * @Author: Jean_Leung
 * @Date: 2024-10-23 14:10:07
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-23 14:49:29
 * @FilePath: \code\dp_leetcode309.cpp
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
        // 在122的条件进行改造
        // dp[i][0] 代表第i天未持有股票的现金
        // dp[i][1] 代表第i天持有股票的现金
        // 冷静期通过for里面实现
        // dp[0][0] = -prices[0]代表第0天持有股票时的现金,
        // 也就是买入第0天股票时候的现金就是-prices[0]
        // dp[1][0] = max(-prices[0], -prices[1]);
        // 第1天未持有股票时候的现金
        // dp[1][1] = max(dp[0][1], dp[0][0] + prices[1]);
        if (prices.size() <= 1) {
            return 0;
        }
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2));
        dp[0][0] = -prices[0];
        dp[1][0] = max(-prices[0], -prices[1]);
        dp[1][1] = max(dp[0][1], dp[0][0] + prices[1]);
        for (int i = 2; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 2][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[prices.size() - 1][1];
    }

    // 代码随想录做法
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        vector<vector<int>> dp(prices.size() + 1, vector<int>(4, 0));
        // 0: 持有股票状态
        // 1: 保持卖出状态
        // 2: 今天卖出股票
        // 3: 今天为冷冻期
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3] - prices[i],
                                             dp[i - 1][1] - prices[i]));
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }
        return max(dp[prices.size() - 1][3],
                   max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]));
    }
};