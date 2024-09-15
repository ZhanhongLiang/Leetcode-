/*
 * @Author: Jean_Leung
 * @Date: 2024-09-12 12:46:08
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-13 20:40:30
 * @FilePath: \code\sliding_window_leetcode904.cpp
 * @Description: 滑动窗口
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

class Solution {
  public:
    int totalFruit(vector<int> &fruits) {
        // 水果成篮题目
        // 需要记录水果的种类
        unordered_map<int, int> win_types; // 记录窗口内水果的种类
        int result = 0;                    // 记录最长的答案区间
        for (int right = 0, left = 0, fruits_type = 0; right < fruits.size();
             right++) {
            // 先增加
            // 如果当前窗口里面right种类是只有一种
            if (++win_types[fruits[right]] == 1) {
                // 窗口种类+1
                fruits_type++;
            }
            // 进行试探
            while (fruits_type > 2) {
                // 如果当前区间左端点满足种类存在，那么就需要窗口种类--
                // 且左指针需要向左移动一位
                if (--win_types[fruits[left]] == 0) {
                    fruits_type--;
                }
                left++;
            }
            // 更新结果值
            result = max(result, right - left + 1);
        }
        return result;
    }
};

// 测试模板
int main(int argc, char const *argv[]) {
    Solution solution;
    vector<int> test_nums{2, 3, 1, 2, 4, 3};
    int ans = solution.totalFruit(test_nums);
    std::cout << "ans:" << ans << std::endl;
    return 0;
}