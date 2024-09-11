/*
 * @Author: Jean_Leung
 * @Date: 2024-09-11 15:16:29
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-11 15:36:26
 * @FilePath: \code\slow_fast_leetcode977.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

#define MAX_ 1e4
#define MIN_ -1e4

class Solution {
  public:
    vector<int> sortedSquares(vector<int> &nums) {
        // 法1:因为不考虑原先数组的位置，所以我们采用双向指针法
        int left = 0;
        int right = nums.size() - 1;
        vector<int> ans(nums.size(), 0);
        // ans.resize(nums.size()); // 设置新数组大小
        int ans_right = ans.size() - 1;
        // 双向指针法
        while (left <= right) {
            if (nums[left] * nums[left] < nums[right] * nums[right]) {
                ans[ans_right--] = nums[right] * nums[right];
                right--;
            } else {
                ans[ans_right--] = nums[left] * nums[left];
                left++;
            }
        }
        return ans;
    }
};
// 测试模板
int main(int argc, char const *argv[]) {
    Solution solution;
    vector<int> test_nums{-7, -3, 2, 3, 11};
    vector<int> ans;
    ans = solution.sortedSquares(test_nums);
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;
    // std::cout << "ans:" << ans << std::endl;
    return 0;
}