/*
 * @Author: Jean_Leung
 * @Date: 2024-10-23 15:32:53
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-23 17:27:01
 * @FilePath: \code\dp_leetcode300.cpp
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

// 贪心算法是否可行??

class Solution {
  public:
    // DP
    int lengthOfLIS(vector<int> &nums) {
        // dp[i]代表i下标(包括i)的最长严格递增序列,但不是连续的
        if (nums.size() <= 1) {
            return nums.size();
        }
        vector<int> dp(nums.size(), 1);
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            for (int k = 1; k < dp.size(); k++) {
                std::cout << dp[k] << " ";
            }
            std::cout << std::endl;
            // 这里没搞懂，dp[i]我已经第一
            //
            if (res < dp[i]) {
                res = dp[i];
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> test{1, 3, 6, 7, 9, 4, 10, 5, 6};
    solution.lengthOfLIS(test);
}