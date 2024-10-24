/*
 * @Author: Jean_Leung
 * @Date: 2024-10-23 17:30:42
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-23 17:33:01
 * @FilePath: \code\dp_leetcode674.cpp
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
    int findLengthOfLCIS(vector<int> &nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        // dp[i]代表以下标i为结尾的连续递增子序列长度
        int res = 0;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            if (res < dp[i]) {
                res = dp[i];
            }
            for (int k = 0; k < dp.size(); k++) {
                std::cout << dp[k] << " ";
            }
            std::cout << std::endl;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> test{1, 3, 5, 4, 7};
    solution.findLengthOfLCIS(test);
}
