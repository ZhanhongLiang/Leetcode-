/*
 * @Author: Jean_Leung
 * @Date: 2024-10-17 15:15:15
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-17 15:35:19
 * @FilePath: \code\greedy_leetcode406.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <list>
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
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        // 用list可以节省时间，因为底层是链表
        list<vector<int>> ans; // 答案数组
        // 因为是贪心思想:先按照身高进行从大到小进行排序
        sort(people.begin(), people.end(), cmp);
        // 然后遍历people数组，优先选择身高教高的,然后按照其第二个数来进行插入下标
        for (auto x : people) {
            int position = x[1];
            auto it = ans.begin();
            while (position--) {
                it++;
            }
            ans.insert(it, x);
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
    bool static cmp(const vector<int> &a, const vector<int> &b) {
        // 优先选择身高较为高的,如果身高相等
        // 则按照小的优先
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }
};