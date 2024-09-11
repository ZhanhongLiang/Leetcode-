/*
 * @Author: Jean_Leung
 * @Date: 2024-09-10 12:35:36
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-11 10:19:45
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
        int slow_index = 0; // 慢指针位置，用于进行交换
        for (int fast_index = 0; fast_index < nums.size(); fast_index++) {
            // 用fast_index 快指针进行遍历整个数组，当nums[fast_index] !=
            // nums[fast_index -
            // 1]的时候，那么就说明前一个数和后一个数不相等，就应该进行slow_index
            // 和fast_index的交换
            // !fast_index是边界条件，因为刚进去的时候，fast_index=0
            if (!fast_index || nums[fast_index] != nums[fast_index - 1]) {
                nums[slow_index] = nums[fast_index];
                slow_index++;
                /* code */
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