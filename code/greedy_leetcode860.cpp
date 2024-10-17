/*
 * @Author: Jean_Leung
 * @Date: 2024-10-17 12:48:28
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-17 12:48:51
 * @FilePath: \code\greedy_leetcode860.cpp
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
    bool lemonadeChange(vector<int> &bills) {
        // 维护5元,10元，20元的三个变量
        // 贪心思想:
        //        1.遇到5元直接收
        //         2.遇到10元找5元
        //         3.遇到20元优先找10元和5元，没有则3张5元
        //         局部最优:如果有10元优先给20找零,没有那么就找3张5元
        int count_five = 0;
        int count_ten = 0;
        int count_twenty = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                count_five++;
            } else if (bills[i] == 10) {
                count_five--;
                count_ten++;
            } else {
                // 优先找10元
                if (count_ten) {
                    count_ten--;
                    count_five--;
                } else {
                    count_five = count_five - 3;
                }
            }
            if (count_five < 0 || count_ten < 0) {
                return false;
            }
        }
        return true;
    }
};