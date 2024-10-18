/*
 * @Author: Jean_Leung
 * @Date: 2024-10-18 09:50:00
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-18 11:17:21
 * @FilePath: \code\greedy_leetcode435.cpp
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
    //
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.size() <= 1) {
            return 0;
        }
        int ans = 1; // 答案, 是1的原因就是数组中第一个区间必然为非交叉区间
        // 快排，需要先按右边界进行排序
        sort(intervals.begin(), intervals.end(), cmp);
        // 记录第一个区间的右边界为非交叉点的边界
        // 从左往右开始遍历，判断下一个区间的左边界是否大于前一个区间的右边界
        int right_board = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            // 记录前一个区间的右边界为非交叉点的边界
            // 判断下一个区间是否大于前一个区间的左边界
            if (intervals[i][0] >= right_board) {
                right_board = intervals[i][1];
                ans++;
            }
        }
        return intervals.size() - ans;
    }

    // 优先右边界小的进行排序
    bool static cmp(const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];
    }
};