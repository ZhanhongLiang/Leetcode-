/*
 * @Author: Jean_Leung
 * @Date: 2024-10-15 13:26:06
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-16 16:20:27
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
    // 贪心算法
    // 局部最优解是:找到波谷和波峰位置
    // 全局最优解:波谷二号波峰最多就是摆动序列最长
    // 注意: 找到波谷和波峰位置也是要分情况的
    //         1.上下坡出现平坡:
    //             1.1 定义pre_diff = 0 && cur_diff > 0 || pre_diff = 0 &&
    //             cur_diff < 0
    //         2.当出现两个数的时候,我们需要将两个数前面第一个数扩充,使得变成三数数组
    //         3.当单调坡出现平坡:
    //         需要坡度变化的时候才能将当前先前的波峰或波谷赋予给当前波峰波谷
    int wiggleMaxLength(vector<int> &nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int pre_diff = 0;
        int cur_diff = 0;
        int res = 1; // 怎么都有一个答案
        // 判断数组出现波峰和波谷
        for (int i = 0; i < nums.size() - 1; i++) {
            cur_diff = nums[i + 1] - nums[i]; // 当前的坡度变化
            if ((pre_diff >= 0 && cur_diff < 0) ||
                (pre_diff <= 0 && cur_diff > 0)) {
                res++;
                pre_diff = cur_diff;
            }
        }
        return res;
    }
};