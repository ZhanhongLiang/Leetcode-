/*
 * @Author: Jean_Leung
 * @Date: 2024-10-24 11:12:01
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-24 11:31:56
 * @FilePath: \code\dp_leetcode1147.cpp
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
    int longestCommonSubsequence(string text1, string text2) {
        // dp[i][j]代表以[0,i-1]为结尾的A, [0,j - 1]为结尾的B的最长公共子序列
        // 当text1[i -1] == text2[j - 1]
        // 也就是以i-1为结尾的A等于以j-1为结尾的B
        // 则dp[i][j]是由上一个状态i-1和j-1推导出来
        // 否则dp[i][j]是由左边和上边推导出来
        vector<vector<int>> dp(text1.size() + 1,
                               vector<int>(text2.size() + 1, 0));
        int res = 0;
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // dp[i][j]由i-1
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                if (res < dp[i][j]) {
                    res = dp[i][j];
                }
            }
            for (int m = 0; m <= text1.size(); m++) {
                for (int n = 0; n <= text2.size(); n++) {
                    std::cout << dp[m][n] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
        return res;
    }
};

int main() {
    Solution solution;
    string text1 = "abcde";
    string text2 = "ace";
    solution.longestCommonSubsequence(text1, text2);
}