/*
 * @Author: Jean_Leung
 * @Date: 2024-09-11 15:16:29
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-12 12:03:51
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
        // 首先题目不要求是有顺序的，所以我们可以使用双向指针法
        // 就是设置双向指针进行比对
        // 然后题目没对空间复杂度进行要求，那么我们可以牺牲空间复杂度来换取时间复杂度
        // int result = INT_MAX;
        vector<int> ans(nums.size(), 0); // 返回答案数组
        int left = 0;
        int ans_right = nums.size() - 1; // 设置答案数组的右侧
        int right = nums.size() - 1;
        while (left <= right) {
            if (nums[left] * nums[left] <= nums[right] * nums[right]) {
                ans[ans_right--] = nums[right] * nums[right];
                right--;
            } else {
                ans[ans_right--] = nums[left] * nums[left];
                left++;
            }
        }
        // 判断边界条件
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