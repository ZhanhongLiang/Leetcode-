/*
 * @Author: Jean_Leung
 * @Date: 2024-09-11 10:27:23
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-12 11:27:03
 * @FilePath: \code\slow_fast_leetcode283.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
  public:
    void MoveZeroes(vector<int> &nums) {
        int slow_index = 0; // 慢指针
        for (int fast_index = 0; fast_index < nums.size(); fast_index++) {
            if (nums[fast_index]) {
                nums[slow_index++] = nums[fast_index];
            }
        }
        while(slow_index < nums.size()){
            nums[slow_index++] = 0;
        }
    }
};

// 测试模板
int main(int argc, char const *argv[]) {
    Solution solution;
    vector<int> test_nums{0, 1, 2, 0, 3, 3, 5, 5, 10};
    for (int i = 0; i < test_nums.size(); i++) {
        std::cout << test_nums[i];
        /* code */
    }
    std::cout << std::endl;
    solution.MoveZeroes(test_nums);
    for (int i = 0; i < test_nums.size(); i++) {
        std::cout << test_nums[i];
        /* code */
    }
    // for (auto val : test_nums) {
    //     std::cout << val;
    // }
    // std::cout << std::endl;
    // solution.MoveZeroes(test_nums);
    // std::cout << "ans:" << ans << std::endl;
    return 0;
}