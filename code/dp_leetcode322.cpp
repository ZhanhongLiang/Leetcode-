/*
 * @Author: Jean_Leung
 * @Date: 2024-10-21 19:32:25
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-21 19:33:00
 * @FilePath: \code\dp_leetcode322.cpp
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
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        // dp[j]代表组成j金额的最小硬币个数
        // dp[j] = min(dp[j], dp[j - coins[i]] + 1)
        dp[0] = 0; // 初始化需要注意
        // 先物品后背包
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                if (dp[j - coins[i]] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        if (dp[amount] == INT_MAX) {
            return -1;
        }
        return dp[amount];
    }

    int coinChangeII(vector<int> &coins, int amount){
        vector<int>dp(amount + 1, INT_MAX);
        dp[0] = 0;
        //先背包后物品
        for(int j = 0; j <= amount; j++){
            for(int i = 0; i < coins.size(); i++){
                if(j - coins[i] >= 0 && dp[j - coins[i]] != INT_MAX){
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        if(dp[amount] == INT_MAX){
            return -1;
        }
        return dp[amount];
    }
};