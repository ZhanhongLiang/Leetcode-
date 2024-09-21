/*
 * @Author: Jean_Leung
 * @Date: 2024-09-20 13:20:16
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-21 12:13:21
 * @FilePath: \code\hash_table_leetcode18.cpp
 * @Description:四数之和
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
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        // 四数之和，和15题的思路相似
        // 不过这个是四个数，所以需要额外的开销
        // 先固定i，后固定j，再设定双指针k和m进行对撞遍历
        // 注意去重和剪枝
        // 先进行排序，因为对撞遍历是满足有序性质的
        sort(nums.begin(), nums.end());
        vector<vector<int>> result; // 答案数组
        // 先固定i
        for (int i = 0; i < nums.size(); i++) {
            // 先剪枝,为什么需要剪枝呢
            // 因为经过排序之后，数组是从小到大的
            // 如果nums[i] > target的话,必然nums[i]+nums[i+1]>target
            // 是递增的,所以是不可能存在满足题意的
            // 经过分析,当nums[i] > target && nums[i] >= 0时候，
            // 必然不存在累加等于target的值
            if (nums[i] > target && nums[i] >= 0) {
                break;
            }
            // 需要去重
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // 第二个固定是j
            for (int j = i + 1; j < nums.size(); j++) {
                // 二级剪枝
                if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) {
                    break;
                }
                // 需要去重
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                // 设置对撞指针
                int k = j + 1;
                int m = nums.size() - 1;
                while (k < m) {
                    if ((long)nums[i] + nums[j] + nums[k] + nums[m] > target) {
                        m--;
                    } else if ((long)nums[i] + nums[j] + nums[k] + nums[m] <
                               target) {
                        k++;
                    } else {
                        //
                        result.push_back({nums[i], nums[j], nums[k], nums[m]});
                        while (k < m && nums[k] == nums[k + 1]) {
                            k++;
                        }
                        while (k < m && nums[m] == nums[m - 1]) {
                            m--;
                        }
                        k++;
                        m--;
                    }
                }
            }
        }
        return result;
    }
};
