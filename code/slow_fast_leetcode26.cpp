/*
 * @Author: Jean_Leung
 * @Date: 2024-09-10 12:35:36
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-10 14:01:38
 * @FilePath: \code\slow_fast_leetcode26.cpp
 * @Description: 移除重复的元素，得到一个不重复的序列且返回处理后的长度
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
    int removeDuplicates(vector<int> &nums) {
        // if (nums.empty())
        //     return 0;
        int slow_index = 0;
        // int target = nums[0]; // 设定每次查询的val值
        for (int fast_index = 0; fast_index < nums.size(); fast_index++) {
            // 如果快指针的数是不等于慢指针的数的话，那么需要进行交换
            // 将慢指针的位置与快指针位置进行交换
            if (!fast_index || nums[fast_index] != nums[fast_index - 1]) {
                nums[slow_index++] = nums[fast_index];
            }
            /* code */
        }
        return slow_index;
    }
};

// 测试模板
int main(int argc, char const *argv[]) {
    Solution solution;
    vector<int> test_nums{0, 1, 2, 3, 3, 5, 5, 10};
    int ans = solution.removeDuplicates(test_nums);
    std::cout << "ans:" << ans << std::endl;
    return 0;
}