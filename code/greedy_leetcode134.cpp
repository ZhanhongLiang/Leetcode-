/*
 * @Author: Jean_Leung
 * @Date: 2024-10-17 10:18:58
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-17 11:35:58
 * @FilePath: \code\greedy_leetcode134.cpp
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
    // 法1:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // 贪心策略:
        //         1.记录res[i]= gas[i] - cost[i]
        //            代表i加油站的剩余油量
        //         2. 记录当前i的cursum区间和,假如区间和<0,cursum是res[i]累加
        //               代表开头位置至少是i+1
        //         3. 记录totalsum,记录整个区间的res[i]累加，如果totalsum>=0
        //                代表可以走通,否则就返回-1,代表走不通
        //         局部最优:就是 res[i]的区间和cur_sum
        //                    一旦小于0,起始位置至少是i+1，因为i之前开始一定是不行的
        //         全局最优: 找到可以跑一圈的起始位置
        int start = 0;     // 车开始位置
        int cur_sum = 0;   // 记录当前i的区间和
        int total_sum = 0; // 记录整个区间的区间和
        // int res[gas.size()]; // 定义res的大小
        // 这里其实也可以用cost开始,
        for (int i = 0; i < gas.size(); i++) {
            // res[i] = gas[i] - cost[i]; // 代表当前i的剩余油量
            cur_sum += gas[i] - cost[i];
            total_sum += gas[i] - cost[i];
            if (cur_sum < 0) {
                // 至少i+1位置开始
                start = i + 1;
                cur_sum = 0; // 重新开始计算
            }
        }
        if (total_sum < 0) {
            return -1;
        }
        return start;
    }

    // 法2:
};