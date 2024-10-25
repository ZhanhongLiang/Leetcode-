/*
 * @Author: Jean_Leung
 * @Date: 2024-10-24 15:04:28
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-25 14:12:48
 * @FilePath: \code\dp_leetcode392.cpp
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
    bool isSubsequence(string s, string t) {
        // dp[i][j]表示以下标i-1为结尾的字符串s和以下标j-1为结尾的字符串t
        // 相同⼦序列的⻓度，所以如果dp[s.size()] [t.size()] 与
        // 字符串s的⻓度相同说明：s与t的最⻓相同⼦序列就是s，那么s 就是 t
        // 的⼦序列。 当text1[i -1] == text2[j - 1]
        // 也就是以i-1为结尾的A等于以j-1为结尾的B
        // 则dp[i][j]是由上一个状态i-1和j-1推导出来
        // 否则dp[i][j]是由左边和上边推导出来
        // if (t.size() == 0 || s.size() == 0) {
        //     return false;
        // }
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        bool res = false;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                // 如果两者的的字符相等
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        if (dp[s.size()][t.size()] == s.size()) {
            return true;
        }
        return false;
    }
};