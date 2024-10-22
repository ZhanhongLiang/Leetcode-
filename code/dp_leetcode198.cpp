/*
 * @Author: Jean_Leung
 * @Date: 2024-10-21 22:22:27
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-21 22:26:55
 * @FilePath: \code\dp_leetcode198.cpp
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
    int rob(vector<int> &nums) {
        // dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
        // dp[i]代表选取i包括i在内房屋的最高金额
        // 初始化为dp[0] = nums[0]
        // dp[1] = max(nums[0], nums[1])
        vector<int> dp(nums.size() + 1, 0);
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};