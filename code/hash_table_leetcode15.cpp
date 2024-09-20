/*
 * @Author: Jean_Leung
 * @Date: 2024-09-19 14:26:03
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-20 13:17:37
 * @FilePath: \code\hash_table_leetcode15.cpp
 * @Description: 三数之和
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
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
    vector<vector<int>> threeSum(vector<int> &nums) {
        // 先排序，使用快排,O(nlogn)复杂度
        // 这道题满足对撞双指针特性，
        // 因为找的是三元组,所以i,j,k代表三个位置的下标
        // 固定i,j递增的时候,k肯定是递减的
        // 这个很容易用反证法来证明
        // 且我们需要去重,去重思路就是i跟i-1位置的数是否相同
        vector<vector<int>> result;     // 答案数组
        sort(nums.begin(), nums.end()); // 快排
        // 先固定i进行遍历
        for (int i = 0; i < nums.size(); i++) {
            // 需要判定去重
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // 否则i的位置数和i-1的位置数并不是重复的
            // 那么需要进行下一步:设定双指针j，k
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                } else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    // 需要去重
                    while (j < k && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k - 1]) {
                        k--;
                    }
                    // 因为通过去重后,nums[j] !=
                    // nums[j+1]，那么就代表着j+1位置才是我们需要的 同理k也是
                    j++;
                    k--;
                }
            }
        }
        return result;
    }
};