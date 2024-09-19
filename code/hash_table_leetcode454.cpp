/*
 * @Author: Jean_Leung
 * @Date: 2024-09-19 13:47:47
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-19 14:15:26
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
        // 记录nums1+nums2:次数，就是key是nums1+nums2,key就是出现从次数
        int ans = 0;
        unordered_map<int, int> sum_map;
        for (auto a : nums1) {
            for (auto b : nums2) {
                sum_map[a + b]++;
            }
        }
        // 再次遍历nums3和nums4，如果里面c+b = -(a+b)的话
        // 那么就结果次数++
        for (auto c : nums3) {
            for (auto d : nums4) {
                ans += sum_map[-(c + d)];
            }
        }
        return ans;
    }
};
