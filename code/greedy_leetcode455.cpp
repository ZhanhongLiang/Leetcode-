/*
 * @Author: Jean_Leung
 * @Date: 2024-10-15 11:49:16
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-15 12:16:02
 * @FilePath: \code\greedy_leetcode455.cpp
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
    // 法一: 思考角度是大饼干先喂大胃口
    int findContentChildren(vector<int> &g, vector<int> &s) {
        // 局部最优是:每次我都要找到最小的s[j]使得其满足s[j]>=g[i]
        // 所以我需要固定g[i],然后遍历是s[j]找出最小
        // 所以需要将孩子和饼干从小到达进行排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        // 还需要记录最大满足孩子数
        int ans = 0;
        // 胃口for,孩子数
        for (int i = g.size() - 1, j = s.size() - 1; i >= 0; i--) {
            // 饼干if
            if (j >= 0 && s[j] >= g[i]) {
                ans++; // 记录满足孩子数
                j--;   // 饼干从最大开始分配
            }
        }
        return ans;
    }

    // 法二:小饼干喂饱小胃口
    int findContentChildren(vector<int> &g, vector<int> &s) {
        // 小饼干喂饱小胃口
        sort(g.begin(), g.begin());
        sort(s.begin(), s.begin());
        int ans = 0;
        int i = 0;
        // 饼干for
        for (int j = 0; j < s.size(); j++) {
            // 胃口if,孩子数
            if (i < g.size() && s[j] >= g[i]) {
                // ans++;
                i++;
            }
        }
        return i;
    }
};