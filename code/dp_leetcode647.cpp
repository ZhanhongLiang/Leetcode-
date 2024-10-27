/*
 * @Author: Jean_Leung
 * @Date: 2024-10-25 15:35:04
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-27 19:55:56
 * @FilePath: \code\dp_leetcode647.cpp
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
    int countSubstrings(string s) {
        // vector<vector<bool>> dp(s.size() + 1, vector<bool>(2,false));
        // dp[i][j] 代表[i,j]区间的字符串是否是回文字符串
        // false代表不是回文字符串,true代表是回文字符串
        // 递推公式:
        //        如果s[i] == s[j]
        //            1.如果j==i,那么肯定是回文字串,dp[i][j] = true;
        //            2.如果j-i == 1,那么也肯定是回文字串,例如aa,dp[i][j]=true;
        //            3.如果j-i > 1,那么需要判断dp[i + 1][j-1]是否是回文字串
        // 因为需要判断i+1和j-1, 且,dp[i][j]是由左下角推导上来的,
        // 也就是遍历顺序必须是从下到上，从左到右
        if (s.size() == 0) {
            return 0;
        }
        vector<vector<bool>> dp(s.size() + 1,
                                vector<bool>(s.size() + 1, false));
        int res = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        dp[i][j] = true;
                        res++;
                    } else if (dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        res++;
                    }
                }
            }
        }
        return res;
    }
};