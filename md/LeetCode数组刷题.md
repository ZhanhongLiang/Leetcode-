# 34. [在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/)

## 题目

>给你一个按照非递减顺序排列的整数数组 `nums`，和一个目标值 `target`。请你找出给定目标值在数组中的开始位置和结束位置。
>
>如果数组中不存在目标值 `target`，返回 `[-1, -1]`。
>
>你必须设计并实现时间复杂度为 `O(log n)` 的算法解决此问题。

**示例 1：**

```
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
```

**示例 2：**

```
输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
```

**示例 3：**

```
输入：nums = [], target = 0
输出：[-1,-1]
```

**提示：**

- `0 <= nums.length <= 105`
- `-109 <= nums[i] <= 109`
- `nums` 是一个非递减数组
- `-109 <= target <= 109`

## 题目大意

>找到数组中目标target值的第一个位置和最后一个位置

## 解题思路

>寻找target在数组里的左右边界，有如下三种情况：
>
>- 情况一：target 在数组范围的右边或者左边，例如数组{3, 4, 5}，target为2或者数组{3, 4, 5},target为6，此时应该返回{-1, -1}
>- 情况二：target 在数组范围中，且数组中不存在target，例如数组{3,6,7},target为5，此时应该返回{-1, -1}
>- 情况三：target 在数组范围中，且数组中存在target，例如数组{3,6,7},target为6，此时应该返回{1, 1}

![](https://pic.superbed.cc/item/66de8806fcada11d37b7a55c.png)

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-08 16:34:39
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-09 13:27:07
 * @FilePath: \code\main.cpp
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
};

int main() {
    Solution solution;
    vector<int> testNums{2, 4, 10, 10, 11, 11, 17, 18};
    vector<int> ans = solution.SearchRange(testNums, 11);
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << std::endl;
    }
    return 0;
}
```

