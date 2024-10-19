/*
 * @Author: Jean_Leung
 * @Date: 2024-10-19 14:43:52
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-19 15:21:22
 * @FilePath: \code\dp_leetcode63.cpp
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
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        // dp[i][j]代表到达第i行，第j列的不同路径数
        // dp[0][0] = 0
        // dp[0][1]=1......dp[0][n-1] = 1
        // dp[1][0]=1......dp[m-1][0] = 1
        // dp[1][1] = dp[0][1] + dp[1][0] = 2;
        // dp[m-1][n-1] = dp[m-2][n-1] + dp[m-1][n-2]
        // dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

        // 然后进行遍历
        int m = obstacleGrid.size();    // 行
        int n = obstacleGrid[0].size(); // 列
        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) {
            return 0;
        }
        // 初始化矩阵为0矩阵
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < n && obstacleGrid[0][i] == 0; i++) {
            dp[0][i] = 1;
        }
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) {
            dp[i][0] = 1;
        }
        // 然后再进行dp操作
        // 需要进行两层遍历
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};