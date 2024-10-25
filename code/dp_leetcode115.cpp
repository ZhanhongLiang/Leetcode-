/*
 * @Author: Jean_Leung
 * @Date: 2024-10-25 14:18:10
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-25 14:54:33
 * @FilePath: \code\dp_leetcode115.cpp
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
    int numDistinct(string s, string t) {
        // dp[i][j]是 以i-1为结尾的s子序列中出现j-1为结尾的t的个数为dp[i][j]
        // 当s[i - 1] == t[i - 1]的时候
        // dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        // 否则dp[i][j] = dp[i - 1][j]
        // 这个我只能画图自己理解一遍,难以理解
        // 为什么当以i-1，j-1为结尾不相等的时候,需要dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
        vector<vector<uint64_t>> dp(s.size() + 1,
                                    vector<uint64_t>(t.size() + 1));
        int res = 0;
        for (int i = 0; i <= s.size(); i++) {
            dp[i][0] = 1;
        }
        for (int j = 1; j <= t.size(); j++) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                // dp[i][]是以i-1，j-1为结尾的子序列长度
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};