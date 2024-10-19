/*
 * @Author: Jean_Leung
 * @Date: 2024-10-19 14:02:27
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-19 14:19:54
 * @FilePath: \code\dp_leetcode62.cpp
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

class Solution {
  public:
    int uniquePaths(int m, int n) {
        // dp[i][j]代表到达第i行，第j列的不同路径数
        // dp[0][0] = 0
        // dp[0][1]=1......dp[0][n-1] = 1
        // dp[1][0]=1......dp[m-1][0] = 1
        // dp[1][1] = dp[0][1] + dp[1][0] = 2;
        // dp[m-1][n-1] = dp[m-2][n-1] + dp[m-1][n-2]
        // dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        int dp[m][n];
        dp[0][0] = 0;
        // 需要对第一列和第一行进行初始化
        for (int i = 1; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i < n; i++) {
            dp[0][i] = 1;
        }
        if (m == 0 && n == 0) {
            return 0;
        }
        if (m == 1 || n == 1) {
            return 1;
        }
        // 需要进行两层遍历
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};