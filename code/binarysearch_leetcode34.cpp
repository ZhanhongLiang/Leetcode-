

/*
 * @Author: Jean_Leung
 * @Date: 2024-09-08 16:34:39
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-09 15:07:10
 * @FilePath: \code\leetcode34.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

// #include "my_array.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

// using namespace std;

// Function to merge two sorted arrays into a single sorted array

class Solution {
  public:
    // 生成随机数组
    vector<int> Nums2Vec() {
        vector<int> nums;
        for (int i = 0; i < 10; i++) {
            nums[i] = random(100);
        }
        return nums;
    }
    // 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
    int SearchInsert(vector<int> &nums, int target) {
        // 二分法查找
        int left = 0;                // 右指针
        int right = nums.size() - 1; // 左指针
        // 当left==right，区间[left, right]依然有效，所以⽤ <=
        while (left <= right) {
            int mid = (left + right) >> 2; // 防⽌溢出 等同于(left + right)/2
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
                /* code */
            } else {
                return mid;
            }
        }
        return left;
    }
    // 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值
    // target。请你找出给定目标值在数组中的开始位置和结束位置。
    // 如果数组中不存在目标值 target，返回 [-1, -1]。
    // 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题
    /**
     * @description: 查找右边界
     * @param {vector<int>} &nums
     * @param {int} target
     * @return {*}
     */
    int SearchRightBorder(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int right_border = -2; // 初始化右边界，先寻找右边界
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
                right_border = left;
            }
        }
        return right_border;
    }
    /**
     * @description: 查找左边界
     * @param {vector<int>} &nums
     * @param {int} target
     * @return {*}
     */
    int SearchLeftBorder(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int left_border = -2; // 初始化左边界，先寻找右边界
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
                left_border = right;
            } else {
                left = mid + 1;
            }
        }
        return left_border;
    }

    vector<int> SearchRange(vector<int> &nums, int target) {
        int left_border = SearchLeftBorder(nums, target);
        int right_border = SearchRightBorder(nums, target);
        // 情况一:
        if (right_border == -2 || left_border == -2)
            return {-1, -1};
        // 情况三:
        if (right_border - left_border > 1)
            return {left_border + 1, right_border - 1};
        // 情况二
        return {-1, -1};
    }

    // 解法二 AC-wing解法
    // 还是套路模板
    vector<int> SearchRangeII(vector<int> &nums, int target) {
        if (nums.empty())
            return {-1, -1};
        // 还是二分查找的模板
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) >> 1; // 算术右移，也就是除2操作
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (nums[right] != target)
            return {-1, -1};
        int L = right; // 找到左端点
        left = 0;
        right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (nums[mid] <= target)
                left = mid;
            else
                right = mid - 1;
        }
        return {L, right};
    }
};

int main() {
    Solution solution;
    vector<int> testNums{2, 4, 10, 10, 11, 11, 17, 18};
    vector<int> ans = solution.SearchRangeII(testNums, 11);
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << std::endl;
    }
    return 0;
}
