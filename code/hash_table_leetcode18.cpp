/*
 * @Author: Jean_Leung
 * @Date: 2024-09-20 13:20:16
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-20 14:00:26
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
        // 同样一个原理
        // 和15题是类似题目
        sort(nums.begin(), nums.end());
        // 我这次固定的是i 和 j的位置
        // 认为i和j不能绑定一起
        // 然后k 和 m的位置是对撞指针方式进行运算
        // 那么最终该算法复杂度是O(n^3)
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > target && nums[i] >= 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size(); j++) {
                // 需要剪枝
                if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) {
                    break;
                }
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                // 再设定对撞指针
                int k = j + 1;
                int m = nums.size() - 1;
                // 防止数据多大溢出
                while (k < m) {
                    if ((long)nums[i] + nums[j] + nums[k] + nums[m] > target) {
                        m--;
                    } else if ((long)nums[i] + nums[j] + nums[k] + nums[m] < target) {
                        k++;
                    } else {
                        result.push_back({nums[i], nums[j], nums[k], nums[m]});
                        // 对k和m进行去重
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
