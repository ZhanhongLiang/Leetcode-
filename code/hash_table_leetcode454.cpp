/*
 * @Author: Jean_Leung
 * @Date: 2024-09-19 13:47:47
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-20 13:05:28
 * @FilePath: \code\hash_table_leetcode454.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;
class Solution {
  public:
    // 如果用暴力法，得固定一个数，然后遍历另外两个数组，时间复杂度太高了，得O(n^3)
    // 按照这道题n<=200,如果那么时间复杂度就是200^3会超时，所以我们不能使用暴力法
    // 这道题需要n^2的时间复杂度才能满足题意
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                     vector<int> &nums4) {
        // 简单题目
        // 思路就是通过map来先查找A+B的sum组合，然后放到map里面里面
        int ans = 0;
        unordered_map<int, int> sum_map; // 找到sum结果对应的map数组
        // 先遍历两个数组，然后找到其sum的总和，通过key:value =
        // sum:count的形式进行映射
        for (auto a : nums1) {
            for (auto b : nums2) {
                sum_map[a + b]++;
            }
        }
        // 然后再寻找c+d = -(a+b)的组合
        for (auto c : nums3) {
            for (auto d : nums4) {
                ans += sum_map[-(c + d)];
            }
        }
        return ans;
    }
};
