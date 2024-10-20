/*
 * @Author: Jean_Leung
 * @Date: 2024-10-20 15:07:48
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-20 16:54:01
 * @FilePath: \code\dp_leetcode416.cpp
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

/**
 * 如果背包容量为target， dp[target]就是装满 背包之后的重量，所以
 * 当 dp[target] == target 的时候，背包装满了。
 */
class Solution {
  public:
    bool canPartition(vector<int> &nums) {
        // dp[j] = max(dp[j],dp[j- weight[i]] + value[i])
        // dp[j]表示
        // 背包总容量（所能装的总重量）是j，放进物品后，背的最⼤重量为dp[j]
        // 初始化为0
        // 题⽬中说：每个数组中的元素不会超过 100，数组的⼤⼩不会超过 200
        // 总和不会⼤于20000，背包最⼤只需要其中⼀半，所以10001⼤⼩就可以了
        vector<int> dp(10001, 0);
        int sum = 0; // nums总和
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1) {
            return false;
        }
        int target = sum / 2;
        // nums[i]代表该背包的重量和价值，都是同一个数
        // 当dp[sum / 2] == sum / 2;
        // 那么就证明能装满
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[target] == target) {
            return true;
        }
        return false;
    }
};