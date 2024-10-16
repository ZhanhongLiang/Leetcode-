/*
 * @Author: Jean_Leung
 * @Date: 2024-10-16 17:46:37
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-16 18:40:16
 * @FilePath: \code\greedy_leetcode45.cpp
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
    // 解法1: 贪心算法
    int jump(vector<int> &nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int cur_distance = 0;  // 当前覆盖的最远距离下标
        int ans = 0;           // 记录走到最大步数
        int next_distance = 0; // 下一步覆盖的最远距离下标
        for (int i = 0; i < nums.size(); i++) {
            // 更新下一步覆盖的最远距离下标
            next_distance = max(i + nums[i], next_distance);
            if (i == cur_distance) {
                ans++;                        // 跳跃一步
                cur_distance = next_distance; // 更新当前覆盖最远的下标
                if (next_distance >= nums.size() - 1) {
                    break;
                }
            }
        }
        return ans;
    }

    // 解法2:DP思想
    // Y神代码
    // f[i]表示跳到点i的最小步数。
    // f[i]可以用反证法证明是单调递增的
    // 反证: 假设f[i]<f[i-1]
    //          但是i必定是有i-1前面跳到i的，那么必然f[i]>=f[i-1]
    //           所以存在矛盾，那么f[i]必定是单调递增的
    // 且f[i]是单调递增1的，这个显然易见，因为都表示最小步数了,那必然
    // f[i] = f[i-1]+1;
    int jump(vector<int> &nums) {
        int n = nums.size();
        vector<int> f(n);
        for (int i = 0, j = 0; i < n; i++) {
            while (j + nums[j] < i) {
                j++;
            }
            f[i] = f[j] + 1;
        }
        return f[n - 1];
    }
};