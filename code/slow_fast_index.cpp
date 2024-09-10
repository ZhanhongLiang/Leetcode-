/*
 * @Author: Jean_Leung
 * @Date: 2024-09-10 11:26:08
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-10 12:23:43
 * @FilePath: \code\slow_fast_index.cpp
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

// 快慢指针模板

class Solution {
  public:
    int RemoveElement(vector<int> &nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            /* code */
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};

// class Solution {
//   public:
//     int removeElement(vector<int> &nums, int val) {
//         int leftIndex = 0;
//         int rightIndex = nums.size() - 1;
//         while (leftIndex <= rightIndex) {
//             // 找左边等于val的元素
//             while (leftIndex <= rightIndex && nums[leftIndex] != val) {
//                 ++leftIndex;
//             }
//             // 找右边不等于val的元素
//             while (leftIndex <= rightIndex && nums[rightIndex] == val) {
//                 --rightIndex;
//             }
//             // 将右边不等于val的元素覆盖左边等于val的元素
//             if (leftIndex < rightIndex) {
//                 nums[leftIndex++] = nums[rightIndex--];
//             }
//         }
//         return leftIndex; // leftIndex⼀定指向了最终数组末尾的下⼀个元素
//     }
// };

int main(int argc, char const *argv[]) {
    Solution solution;
    vector<int> test_nums{0, 1, 2, 3, 3, 0, 4, 2};
    int ans = solution.RemoveElement(test_nums, 2);
    std::cout << "ans:" << ans << std::endl;
    return 0;
}
