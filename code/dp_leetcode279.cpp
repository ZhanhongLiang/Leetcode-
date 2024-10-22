/*
 * @Author: Jean_Leung
 * @Date: 2024-10-21 20:07:17
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-21 20:08:42
 * @FilePath: \code\dp_leetcode279.cpp
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
    int numSquares(int n) {
        // dp[j] 代表组成j的最少完全平方数的数量
        // dp[j] = min(dp[j], dp[j - i * i] + 1)
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i * i <= n; i++) {
            for (int j = i * i; j <= n; j++) {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
};