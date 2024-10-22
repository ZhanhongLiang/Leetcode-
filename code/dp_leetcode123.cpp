/*
 * @Author: Jean_Leung
 * @Date: 2024-10-22 16:04:21
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-22 17:33:54
 * @FilePath: \code\dp_leetcode123.cpp
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
        // dp[i][1] 代表第i天第一次持有股票拥有的现金
        // dp[i][2] 代表第i天第一次未持有股票拥有的现金
        // dp[i][3] 代表第i天第二次持有股票拥有的现金
        // dp[i][4] 代表第i天第二次未持有股票拥有的现金
        // dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] - prices[i])
        // dp[i][2]= max(dp[i - 1][2], dp[i - 1][1] + prices[i])
        // dp[i][3] = max(dp[i - 1][3], dp[i - 1][4] - prices[i])
        // dp[i][4]= max(dp[i - 1][4], dp[i - 1][3] + prices[i])
        vector<vector<int>> dp(prices.size() + 1, vector<int>(5));
        dp[0][1] -= prices[0];
        dp[0][2] = 0;
        dp[0][3] -= prices[0];
        dp[0][4] = 0;
        for (int i = 1; i < prices.size(); i++) {
            // 为什么需要设置0状态
            // dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
            // for (int i = 0; i < dp.size(); i++) {
            //     for (int j = 0; j < dp[0].size(); j++) {
            //         std::cout << dp[i][j] << " ";
            //     }
            // }
            // std::cout << std::endl;
        }
        return dp[prices.size() - 1][4];
    }
};

int main() {
    Solution solution;
    vector<int> test{3, 3, 5, 0, 0, 3, 1, 4};
    solution.maxProfit(test);
}
