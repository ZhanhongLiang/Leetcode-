/*
 * @Author: Jean_Leung
 * @Date: 2024-09-19 12:16:28
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-19 13:37:44
 * @FilePath: \code\hash_table_leetcode349.cpp
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
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        // 找出两个数组的交集
        // 且输出结果中每个元素一定是唯一的
        // 不考虑 输出结果的顺序
        vector<int> ans; // 答案数组
        unordered_map<int, int> nums1_hash;
        for (auto x : nums1) {
            if (nums1_hash[x] == 0) {
                nums1_hash[x]++; // 统计唯一
            }
        }
        // 再次判断,nums里面的里面是否存在数组
        for (auto x : nums2) {
            if (--nums1_hash[x] == 0) {
                ans.push_back(x);
            }
        }
        return ans;
    }

    // 方法二因为是需要里面的数组是出现一次那么可以
    // 可以用unordered_set来作为容器存储数字
    // 因为限定了0 <= nums1[i] <= 1000
    // 且 1 <= nums1.lenght <= 1000
    vector<int> intersectionII(vector<int> &nums1, vector<int> &nums2) {
        int nums_hash[1001] = {0};
        unordered_set<int> nums_set;
        // 记录每个数字
        for (auto x : nums1) {
            nums_hash[x] = 1;
        }
        for (auto x : nums2) {
            if (nums_hash[x] == 1) {
                nums_set.insert(x);
            }
        }
        return vector<int>{nums_set.begin(), nums_set.end()};
    }
};