/*
 * @Author: Jean_Leung
 * @Date: 2024-10-10 19:16:41
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-10 20:04:54
 * @FilePath: \code\backtracking_leetcode39.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
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
 * void backtracking(参数) {
        if (终⽌条件) {
            存放结果;
            return;
        }
        for (选择：本层集合中元素（树中节点孩⼦的数量就是集合的⼤⼩）) {
            处理节点;
            backtracking(路径，选择列表); // 递归
            回溯，撤销处理结果
        }
    }
 */

class Solution {
  public:
    vector<vector<int>> res; // 结果集合
    vector<int> path;        // 路径
    int sum = 0;             // 总和
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        if (candidates.size() == 0) {
            return res;
        }
        backtracking(candidates, target, 0);
        return res;
    }

    void backtracking(vector<int> &candidates, int target, int start_index) {
        // 终止条件
        if (sum > target) {
            return;
        }
        // 终止条件
        if (sum == target) {
            res.push_back(path);
            return;
        }
        // 递归条件
        for (int i = start_index; i < candidates.size(); i++) {
            sum += candidates[i]; // 累加
            path.push_back(candidates[i]);
            backtracking(candidates, target, i);
            sum -= candidates[i]; // 回溯
            path.pop_back();      // 回溯
        }
    }
};