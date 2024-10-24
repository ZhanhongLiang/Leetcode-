/*
 * @Author: Jean_Leung
 * @Date: 2024-10-23 17:57:38
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-24 11:05:02
 * @FilePath: \code\dp_leetcode718.cpp
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
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        // dp[i][j]代表以i为结尾的nums1，j为结尾的nums2中最长的公共数组
        // dp[i][j]遍历顺序是以先
        vector<vector<int>> dp(nums1.size() + 1,
                               vector<int>(nums2.size() + 1, 0));
        int res = 0; // ans
        // 因为dp[i][j]是以A[i - 1]和B[j - 1]为结尾的公共最长数组
        // 所以i需要遍历到nums1.size()位置
        // j也需要遍历到nums2.size()位置
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (res < dp[i][j]) {
                    res = dp[i][j];
                }
            }
            // for (int k = 0; k <= nums1.size(); k++) {
            //     for (int m = 0; m <= nums2.size(); m++) {
            //         std::cout << dp[k][m] << " ";
            //     }
            //     std::cout << std::endl;
            // }
            // std::cout << std::endl;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> test1{1, 2, 3, 2, 1};
    vector<int> test2{3, 2, 1, 4, 7};
    solution.findLength(test1, test2);
}