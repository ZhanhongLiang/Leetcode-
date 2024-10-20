/*
 * @Author: Jean_Leung
 * @Date: 2024-10-20 17:06:27
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-20 17:36:23
 * @FilePath: \code\dp_leetcode1049.cpp
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
 *  DP五部曲:
 *  1. 确定dp数组（dp table）以及下标的含义
    2. 确定递推公式
    3. dp数组如何初始化
    4. 确定遍历顺序
    5. 举例推导dp数组
 */

class Solution {
  public:
    int lastStoneWeightII(vector<int> &stones) {
        // dp[j]的含义是j背包容量时候，放进物品后
        //       所能容纳的最大容量
        // dp[j] = max(dp[j],dp[j- stones[i]] + stones[i])
        // 最核心的思想是: 分出两堆重量相当的区间,然后俩俩进行碰撞
        // 最后剩下必然是最小的石头
        // 30 * 100 / 2 = 150000
        vector<int> dp(150001, 0);
        int weight = 0;
        for (int i = 0; i < stones.size(); i++) {
            weight += stones[i];
        }
        int target = weight / 2;
        for (int i = 0; i < stones.size(); i++) {
            for (int j = target; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        // 最后得到的必然是两堆重量差不多的区间
        return weight - dp[target] - dp[target];
    }
};