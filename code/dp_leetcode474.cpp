/*
 * @Author: Jean_Leung
 * @Date: 2024-10-21 11:37:37
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-21 13:49:48
 * @FilePath: \code\dp_leetcode474.cpp
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
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // 每次遍历一个字符串
        for (string s : strs) {
            int zeros_nums = 0;
            int one_nums = 0;
            for (char c : s) {
                if (c == '0') {
                    zeros_nums++;
                } else {
                    one_nums++;
                }
            }
            //
            for (int i = m; i >= zeros_nums; i--) {
                for (int j = n; j >= one_nums; j--) {
                    dp[i][j] =
                        max(dp[i][j], dp[i - zeros_nums][j - one_nums] + 1);
                }
            }
        }
        return dp[m][n];
    }
};