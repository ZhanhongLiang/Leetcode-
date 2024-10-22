/*
 * @Author: Jean_Leung
 * @Date: 2024-10-22 14:26:39
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-22 15:30:33
 * @FilePath: \code\dp_leetcode121.cpp
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
        // 贪心解法:
        // 局部最优解是: 找到最小的左边值,然后找到最大的左边值
        int low = INT_MAX;
        int ans = 0;
        for (int i = 0; i < prices.size(); i++) {
            low = min(low, prices[i]);
            ans = max(ans, prices[i] - low);
        }
        return ans;
    }

    // 动态规划
    int maxProfitII(vector<int> &prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        // dp[i][0]代表第i天持有股票所得最多现金
        // dp[i][1]代表第i天不持有股票所得最多现金
        // 持有不代表买入,有可能是昨天就买入了,今天保持持有的状态
        // 递推公式
        // max{前一天不持有股票的现金,今天卖出后的持有的现金}
        // dp[i][0] = max(dp[i - 1][0], -prices[i]);
        // max{前一天不持有股票最多现金,前一天持有股票最多现金+今天卖出股票的价格}
        // dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i])
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[prices.size() - 1][1];
    }
};