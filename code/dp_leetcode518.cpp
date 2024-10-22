/*
 * @Author: Jean_Leung
 * @Date: 2024-10-21 15:09:58
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-21 19:09:09
 * @FilePath: \code\dp_leetcode518.cpp
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
    void change(int amount, vector<int> &coins) {
        // dp[j]代表达到j金额数有几种组合方式
        // dp[j] += dp[j - coins[i]]
        // 因为拥有物品0有dp[0]种方法,再拥有物品1有dp[0] + dp[1]方法
        // 注意这里如果是int会过不了,会导致溢出
        vector<unsigned> dp(amount + 1, 0);
        // 初始化为1,注意达到j金额也有1种方案
        dp[0] = 1;
        // 需要先物品再背包
        // for (int i = 0; i < coins.size(); i++) {
        //     for (int j = coins[i]; j <= amount; j++) {
        //         dp[j] += dp[j - coins[i]];
        //     }
        // }
        for (int j = 0; j <= amount; j++) {
            for (int i = 0; i < coins.size(); i++) {
                if (j - coins[i] >= 0) {
                    dp[j] += dp[j - coins[i]];
                }
            }
            for (int i = 0; i < dp.size(); i++) {
                std::cout << dp[i] << " ";
            }
            std::cout << std::endl;
        }
        // for (auto x : coins) {
        //     for (int i = x; i <= amount; i++) {
        //         dp[i] += dp[i - x];
        //     }
        // }
        // return dp[amount];
    }
};

int main() {
    Solution solution;
    vector<int> test{1, 2, 5};
    solution.change(5, test);
}