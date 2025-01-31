/*
 * @Author: Jean_Leung
 * @Date: 2024-10-25 15:15:40
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-25 15:16:07
 * @FilePath: \code\dp_leetcode72.cpp
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
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size()));
        // 动态规划来做
        // dp[i][j] 代表以i-1为结尾的word1要变成以j-1为结尾的word2的最少操作数
        for (int i = 0; i <= word1.size(); i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= word2.size(); j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min({dp[i - 1][j - 1] + 1, dp[i][j - 1] + 1,
                                    dp[i - 1][j] + 1});
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};