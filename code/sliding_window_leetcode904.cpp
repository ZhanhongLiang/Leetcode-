/*
 * @Author: Jean_Leung
 * @Date: 2024-09-12 12:46:08
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-12 13:36:07
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
    int totalFruit(vector<int>& fruits) {
        int result = INT_MIN; // 记录滑动窗口的长度
        // vector<int> type(2, -1); // 初始化数组，记录水果的种类
        unordered_map<int, int> types; // 维护哈希表，就是key:value值的哈希表
        for (int right = 0, left = 0, win_types = 0; right < fruits.size();
             right++) {
            // 如果哈希表代表的key第一次存在，那么需要++
            if (++types[fruits[right]] == 1) {
                win_types++; // 代表窗口区间的种类
            }
            // 需要移动left指针，来试探
            while (win_types > 2) {
                // 如果left位置的哈希表==0，那么需要left向前移动
                // 且当前窗口种类减一,win_types--;
                if (--types[fruits[left]] == 0) {
                    win_types--;
                }
                left++;
            }
            result = max(result, right - left + 1);
        }
        if (result == INT_MIN) {
            result = 0;
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