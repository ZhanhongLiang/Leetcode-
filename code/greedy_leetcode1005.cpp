/*
 * @Author: Jean_Leung
 * @Date: 2024-10-15 11:49:16
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-17 11:39:00
 * @FilePath: \code\greedy_leetcode1005.cpp
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
    static bool cmp(int a, int b) { return abs(a) > abs(b); }
    // 时间复杂度是O(nlogn);
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        // K次取反后最大化的数组和
        // 贪心算法:
        // 两次贪心算法思想:
        //            1.先按照绝对值大小进行从小到大排序
        //            2.然后将数组所有的负数变成正数,k--
        //            3.再次遍历,将最小值进行反复反转,直到
        //            4.所有结果值进行加和
        // 其实这道题我不认为是贪心策略
        int count = 0;
        if (nums.size() == 0) {
            return count;
        }
        // 按照绝对值进行从大到小进行排序
        sort(nums.begin(), nums.end(), cmp);
        // 然后遍历找数组的负数
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 && k > 0) {
                nums[i] = -nums[i];
                k--;
            }
        }
        // 然后当k>0的时候,需要将最小值进行反复反转
        while (k--) {
            nums[nums.size() - 1] = -nums[nums.size() - 1];
        }
        // 将所有结果值进行加和
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
        }
        return count;
    }
};