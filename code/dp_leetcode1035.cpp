/*
 * @Author: Jean_Leung
 * @Date: 2024-10-24 11:39:32
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-24 11:42:51
 * @FilePath: \code\dp_leetcode1035.cpp
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
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
        // dp[i][j] 代表[0, i - 1]的nums1和[0,j - 1]nums2的公共最长子序列
        // 和1147题目一摸一样，就是求解两个数组的公共最长子序列
        vector<vector<int>> dp(nums1.size() + 1,
                               vector<int>(nums2.size() + 1, 0));
        int res = 0;
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                if (res < dp[i][j]) {
                    res = dp[i][j];
                }
            }
        }
        return res;
    }
};