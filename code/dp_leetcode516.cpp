/*
 * @Author: Jean_Leung
 * @Date: 2024-10-25 15:36:20
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-27 20:09:18
 * @FilePath: \code\dp_leetcode516.cpp
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
    int longestPalindromeSubseq(string s) {
        // 找出最长的回文字符子序列
        // 子序列是不连续的
        // dp[i][j]字符串在[i,j]范围内最长的回文子序列的长度
        // 递推公式:
        //        如果s[i] == s[j]
        //           dp[i][j] = dp[i+1][j-1]+2
        //        不相等
        //           需要分别加入s[i]和s[j]看那个是最大
        //            dp[i][j] = max(dp[i+1][j], dp[i][j - 1])
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, 0));
        // 需要将所有单个字符初始化为回文串长度为1
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;
        }
        // 还是从左上角开始遍历
        // 且j = i + 1
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};