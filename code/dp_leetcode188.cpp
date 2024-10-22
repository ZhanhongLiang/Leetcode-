/*
 * @Author: Jean_Leung
 * @Date: 2024-10-22 18:21:56
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-22 21:33:34
 * @FilePath: \code\dp_leetcode188.cpp
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
    int maxProfit(int k, vector<int> &prices) {
        // k次交易，最多获得的利润
        // 所以有2 * k 次表示买入和卖出
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2 * k + 1, 0));
        // 先要初始化
        for (int i = 1; i < 2 * k; i += 2) {
            dp[0][i] -= prices[0];
        }
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 0; j < 2 * k - 1; j += 2) {
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
                dp[i][j + 2] =
                    max(dp[i - 1][j + 2], dp[i - 1][j + 1] - prices[i]);
            }
        }
        return dp[prices.size() - 1][2 * k];
    }
};