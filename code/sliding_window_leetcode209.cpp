/*
 * @Author: Jean_Leung
 * @Date: 2024-09-11 15:55:21
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-11 16:30:51
 * @FilePath: \code\sliding_window_leetcode209.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

class Solution {
  public:
    // 代码随想录写法
    int minSubArrayLen(int target, vector<int> &nums) {
        int left = 0; // 窗口左指针
        // int right = 0;        // 窗口右指针
        int window_lenght = 0; // 窗口长度
        int sum = 0;           // 窗口总和
        int result = INT_MAX;  // 结果
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right]; // 窗口想右移动
            while (sum >= target) {
                window_lenght = (right - left + 1); // 计算当前窗口长度
                result = result < window_lenght ? result
                                                : window_lenght; // 更新结果值
                // left++;// 窗口左指针向右移动
                sum -= nums[left++];
            }
        }
        return result == INT_MAX ? 0 : result;
    }

    // AC-WINGS Y神写法
    int minSubArrayLenII(int target, vector<int> &nums) {
        int result = INT_MAX; // 结果
        for (int left = 0, sum = 0, right = 0; right < nums.size(); right++) {
            sum += nums[right]; // 右指针不懂，sum加上nums[right]
            while (sum - nums[left] >= target) {
                // 试探窗口左指针的最大值，也就是试探窗口最小值
                sum -= nums[left++];
            }
            if (sum >= target) {
                // 需要做一次判断，可能有特殊情况出现,找到result的值,然后存进result里面
                result = min(result, right - left + 1);
            }
        }
        if (result == INT_MAX) {
            result = 0;
        }
        return result;
    }
};
// 测试模板
int main(int argc, char const *argv[]) {
    Solution solution;
    vector<int> test_nums{2, 3, 1, 2, 4, 3};
    int ans = solution.minSubArrayLenII(7, test_nums);
    std::cout << "ans:" << ans << std::endl;
    return 0;
}