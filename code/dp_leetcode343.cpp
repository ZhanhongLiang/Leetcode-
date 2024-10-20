/*
 * @Author: Jean_Leung
 * @Date: 2024-10-20 12:22:18
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-20 12:55:33
 * @FilePath: \code\dp_leetcode343.cpp
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
    int integerBreak(int n) {
        // dp[i]代表第i个数的最大拆分乘积
        //  dp[i] = max(dp[i],j*(i-j),dp[i - j]* j)
        // 不用初始化dp[1]和dp[0]，
        // 因为这两个数没有含义
        // 关键在于j <= i / 2
        vector<int> dp(n + 2);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};