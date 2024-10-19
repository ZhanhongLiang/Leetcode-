/*
 * @Author: Jean_Leung
 * @Date: 2024-10-19 12:54:09
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-19 13:14:28
 * @FilePath: \code\dp_leetcode509.cpp
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
    int fib(int n) {
        // dp[i]的含义是第i个数的斐波那契数
        // dp[i] = dp[i - 1] + dp[i - 2], i >= 2
        // 初始化dp[1] = 1, dp[0] = 0;
        // 从2开始遍历
        int dp[n + 2];
        dp[0] = 0;
        dp[1] = 1;
        if (n <= 1) {
            return dp[n];
        }
        // 遍历顺序
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};