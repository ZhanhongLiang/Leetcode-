/*
 * @Author: Jean_Leung
 * @Date: 2024-10-21 10:28:06
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-21 10:39:44
 * @FilePath: \code\dp_leetcode494.cpp
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
    int findTargetSumWays(vector<int> &nums, int target) {
        // 由left组合 - right组合 = target
        // 由left + right = sum
        // right = (left - target)
        // right = sum - left
        // sum - left = left - target
        // 则 left = (sum + target) / 2
        // sum 和 target是固定值
        // 也就是找到可以可以组成left的组合数
        // dp[j] 代表j背包容量时候, 可以填满背包的组合数
        // dp[j] += dp[j - nums[i]]
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if ((sum + target) % 2 == 1) {
            return 0;
        }
        if (abs(target) > sum) {
            return 0;
        }
        int bag_size = (sum + target) / 2;
        vector<int> dp(bag_size + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bag_size; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bag_size];
    }
};