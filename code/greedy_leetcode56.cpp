/*
 * @Author: Jean_Leung
 * @Date: 2024-10-18 15:03:08
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-18 15:37:58
 * @FilePath: \code\greedy_leetcode56.cpp
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

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        list<vector<int>> ans; // 答案数组
        if (intervals.size() <= 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        // 首先优先以右边界从小到大进行排序
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= ans.back()[1]) {
                // 需要合并
                // 将结果数组中最后一位的右边界换成两者中最大的
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
                // 将这个替换掉前一个数
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }

    bool static cmp(const vector<int> &a, const vector<int> &b) {
        // 优先以左边界进行从小到大的排序
        return a[0] < b[0];
    }
};