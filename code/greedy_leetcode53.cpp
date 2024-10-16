/*
 * @Author: Jean_Leung
 * @Date: 2024-10-16 16:21:38
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-16 16:51:17
 * @FilePath: \code\greedy_leetcode53.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

/**
 *贪⼼算法⼀般分为如下四步：
    将问题分解为若⼲个⼦问题
    找出适合的贪⼼策略
    求解每⼀个⼦问题的最优解
    将局部最优解堆叠成全局最优解
        这个四步其实过于理论化了，我们平时在做贪⼼类的题⽬
        很难去按照这四步去思考，真是有点“鸡肋”。 做题的时候，只要想清楚 局部最优
        是什么，如果推导出全局最优，其实就够了。
 */

class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        // 贪心算法: 如何辨别出这道题是用贪心算法呢??
        // 我们尝试用滑动窗口法解决,但是发现数组是无序且不符合单调性,不能用滑动窗口法解决
        // 尝试一下找出局部最优: 记录count,当现在count是负数的时候
        //                       就需要重置count为0了,重新从nums[i+1]位置进行加和
        //                        `尽量找出count为正数的时候,保证当前连续加和是为正数`
        // 每部局部最优就能找出全局最优解
        int count = 0;     // 记录局部加和
        int res = INT_MIN; // 记录答案
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i]; // 进行加和
            if (count > res) {
                res = count;
            }
            if (count < 0) {
                // 立即重置count
                count = 0;
            }
        }
        return res;
    }
};