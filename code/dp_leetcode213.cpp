/*
 * @Author: Jean_Leung
 * @Date: 2024-10-21 22:50:56
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-22 11:52:37
 * @FilePath: \code\dp_leetcode213.cpp
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
    // 参考代码随想录的思想
    // 将区间分为三种情况
    // 1 {6 1 9} 1:情况1,代表括住的区间是要`考虑的`
    // {1 6 1 9} 1:情况2,代表括住的区间是要考虑
    // 1 {6 1 9 1}:情况3,代表括住的区间是要考虑
    // 但是观察情况2和情况3是包含情况1的
    int rob(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        // 选择区间
        int left = robFun(nums, 0, nums.size() - 2);
        int right = robFun(nums, 1, nums.size() - 1);
        return max(left, right);
    }

    // 开始区间和结束区间
    int robFun(vector<int> &nums, int start, int end) {
        if (end == start) {
            return nums[start];
        }
        vector<int> dp(nums.size() + 1, 0);
        // 注意这里开始是start
        // 并不是0,也就是将0替换成start开始位置
        // start+1位置也不是1,将start+1替换成1
        // 因为区间开始和结束是不一样的
        dp[start] = nums[start];
        // dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 2])
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[end];
    }
};