/*
 * @Author: Jean_Leung
 * @Date: 2024-10-15 13:26:06
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-15 14:12:01
 * @FilePath: \code\greedy_leetcode376.cpp
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
    // 摆动序列,返回nums中最长的摆动序列
    // 摆动序列就是数组中连续的数之间的差是正负交替的
    // 必须正负，零也不行
    // 数的大小为0<=nums[i]<=1000
    // 数组长度大小为 1 <= nums.length <= 1000
    int wiggleMaxLength(vector<int> &nums) {
        // 局部最优解就是: 出现峰值的点
        // 全局最优解:统计整个数组出现峰值的点就行
        if (nums.size() <= 1) {
            return nums.size();
        }
        int pre_diff = 0;
        int cur_diff = 0;
        int res = 1; // 必然存在一个,两个数也存在一个
        // 情况一: 当上下坡出现平坡时候---pre_diff >= 0 && cur_diff < 0
        //             或者 pre_diff <= 0 && cur_diff < 0
        //                这就是坡度发生变化的情况
        // 情况二:
        // 当单调坡出现出现平坡时候---当出现坡度变化才令pre_diff=cur_diff更新坡度
        // 情况三: 数组首部和尾部的情况,当数组大小为2的时候
        for (int i = 0; i < nums.size() - 1; i++) {
            // 记录当前的坡度
            cur_diff = nums[i + 1] - nums[i];
            //
            if ((pre_diff >= 0 && cur_diff < 0) ||
                (pre_diff <= 0 && cur_diff > 0)) {
                res++; // 波谷波峰+1
                pre_diff = cur_diff;
            }
        }
        return res;
    }
};