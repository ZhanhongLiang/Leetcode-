/*
 * @Author: Jean_Leung
 * @Date: 2024-10-24 11:52:36
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-24 15:04:22
 * @FilePath: \code\dp_leetcode53.cpp
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
    2. 确定递推公式ss
    3. dp数组如何初始化
    4. 确定遍历顺序
    5. 举例推导dp数组
 */

class Solution {
  public:
    // 先考虑dp怎么写
    // dp[i]代表到i下标位置的连续数组拥有最大和
    // dp[i] = max(dp[i - 1] + nums[i], nums[i])
    // 如果dp[i - 1] + nums[i]是比nums[i]小的话,那么就代表nums[i]是负数
    // 需要重新开始
    int maxSubArray(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> dp(nums.size() + 1, 0);
        dp[0] = nums[0];
        int res = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            // 因为如果dp[i - 1]加上当前位置的数，是变小的话
            // 那么就代表nums[i]是负数
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (res < dp[i]) {
                res = dp[i];
            }
        }
        return res;
    }
};