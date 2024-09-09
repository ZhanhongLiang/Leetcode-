/*
 * @Author: Jean_Leung
 * @Date: 2024-09-09 15:58:20
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-09 16:29:32
 * @FilePath: \code\leetcode367.cpp
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
    bool isPerfectSquare(int num) {
        // 二分查找法
        // 寻找 y^2 <= x,也就是找到最大的y使得左边等式成立
        int left = 1;
        int right = num;
        while (left < right) {
            // int mid = (left + (right - left) / 2) + 1; // 因为left =
            // mid，所以我们需要补1
            int mid = left + 1ll + right >> 1;
            if (mid <= num / mid) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return right * right == num;
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    // int y = 5;
    bool ans = solution.isPerfectSquare(5);
    std::cout << ans << std::endl;
    return 0;
}
