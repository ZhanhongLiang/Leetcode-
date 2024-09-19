/*
 * @Author: Jean_Leung
 * @Date: 2024-09-19 14:26:03
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-19 15:21:22
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
        // 分析时间复杂度,如果每次遍历的话
        // 暴力法的话，需要每次固定一个数进行遍历,需要的是O(n^3)肯定会超时
        // 还是O(n^2)
        // 这个必须要先排序，从小到大进行排序，才能用对撞双指针法
        // 为什么能用双指针法呢? 因为当固定i的时候，nums[i]已经固定了
        // 假设nums[i] + nums[j] + nums[k] >= 0
        // 用反证法容易得,当固定nums[i]的时候,令nums[i] = C
        // 那么容易得nums[j] + nums[k] + C >= 0
        // nums[j]递增，nums[k]肯定是递减的
        sort(nums.begin(), nums.end()); // 先进行排序，默认是从小到大进行排序
        vector<vector<int>> ans;
        // 然后固定i进行双指针法
        for (int i = 0; i < nums.size(); i++) {
            // 如果第一个数大于零，必定不存在满足条件的三元组
            // 因为第一个数是最小的
            if (nums[i] > 0) {
                return ans;
            }
            // 进行双指针
            // 因为要规避重复，需要每次判断一下当前nums[i]和nums[i-1]位置是否相同
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int c = nums[i];
            // 进行双指针
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (c + nums[j] + nums[k] > 0) {
                    k--;
                } else if (c + nums[j] + nums[k] < 0) {
                    j++;
                } else {
                    ans.push_back({c, nums[j], nums[k]});
                    // 还需要去重
                    while (j < k && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k - 1]) {
                        k--;
                    }
                    j++;
                    k--;
                }
            }
        }
        return ans;
    }
};