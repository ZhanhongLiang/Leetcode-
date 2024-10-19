/*
 * @Author: Jean_Leung
 * @Date: 2024-10-19 13:16:50
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-19 15:28:16
 * @FilePath: \code\dp_leetcode70.cpp
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
    int climbStairs(int n) {
        int dp[n + 3];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        if (n <= 3) {
            return n;
        }
        for (int i = 4; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i-2];
        }
        return dp[n];
    }
};