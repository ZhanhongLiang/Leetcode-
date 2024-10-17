/*
 * @Author: Jean_Leung
 * @Date: 2024-10-17 15:39:27
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-17 16:01:11
 * @FilePath: \code\greedy_leetcode452.cpp
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
    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.size() == 0) {
            return 0;
        }
        int ans = 1; // 箭的数目
        // 先按照开始位置进行排序
        sort(points.begin(), points.end(), cmp);
        // 贪心思想,需
        // 局部最优: 找到尽可能多的公共区域在一起射气球
        // 全局最优: 把所有气球射爆所用箭最少
        for (int i = 1; i < points.size(); i++) {
            // 如果当前的i的左边界比上一个i的右边界小
            // 那么就是两个重叠了，就需要将当前气球的右边界取min(当前有边界，前一个右边界)
            if (points[i][0] <= points[i - 1][1]) {
                points[i][1] = min(points[i][1], points[i - 1][1]);
            } else {
                ans++;
            }
        }
        return ans;
    }

    bool static cmp(const vector<int> &a, vector<int> &b) {
        // 按照start位置进行排序
        return a[0] < b[0];
    }
};