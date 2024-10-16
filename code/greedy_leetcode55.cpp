/*
 * @Author: Jean_Leung
 * @Date: 2024-10-16 17:21:36
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-16 17:21:47
 * @FilePath: \code\greedy_leetcode55.cpp
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
    bool canJump(vector<int> &nums) {
        // 这道题有难度,我没想出来cover的思想
        // cover表示当前整个数组能cover到最大下标值
        int cover = 0;
        for (int i = 0; i <= cover; i++) {
            // 需要更新当前走到的cover数
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
};