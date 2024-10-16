/*
 * @Author: Jean_Leung
 * @Date: 2024-10-16 16:56:23
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-16 17:16:24
 * @FilePath: \code\greedy_leetcode122.cpp
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
    // 贪心1:
    int maxProfit(vector<int> &prices) {
        int pre_diff = 0;
        int cur_diff = 0;
        int res = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            cur_diff = prices[i + 1] - prices[i]; // 当前差值
            // 当特殊情况
            // 1. 上下坡出现平坡,那么pre_diff == 0 && cur_diff > 0
            //                 就进行加和
            // 2. 一直为单调递增坡的时候
            //                 就需要pre_diff >0 && cur_diff > 0
            if ((pre_diff <= 0 && cur_diff > 0) ||
                (pre_diff > 0 && cur_diff > 0)) {
                res += cur_diff;
            }
            pre_diff = cur_diff;
        }
        return res;
    }

    // 法二还是贪心2:
    // 代码随想录法
    int maxProfit(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            res += max(prices[i] - prices[i - 1], 0);
        }
        return res;
    }
};