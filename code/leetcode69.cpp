/*
 * @Author: Jean_Leung
 * @Date: 2024-09-09 15:10:05
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-09 15:38:53
 * @FilePath: \code\leetcode69.cpp
 * @Description: LeetCode 69
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
    int mySqrt(int x) {
        // 二分查找法
        // 寻找 y^2 <= x,也就是找到最大的y使得左边等式成立
        int left = 0;
        int right = x;
        while (left < right) {
            int mid =
                (left + (right - left) / 2) + 1; // 因为left = mid，所以我们需要补1
            if (mid <= x / mid) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    int y = 8;
    int ans = solution.mySqrt(8);
    std::cout << ans << std::endl;
    return 0;
}
