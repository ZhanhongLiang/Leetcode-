/*
 * @Author: Jean_Leung
 * @Date: 2024-10-10 19:16:41
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-11 12:44:36
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
    // Y神写法
    void backtrackingII(vector<int> &candidates, int u, int target) {
        // 终止条件
        if (target == 0) {
            res.push_back(path);
            return;
        }
        // 如果当前枚举的下标等于数组了
        // 那就没有
        if (u == candidates.size()) {
            return;
        }
        for (int i = 0; candidates[u] * i <= target; i++) {
            // 这里u+1也包含了回溯的思想
            backtracking(candidates, u + 1, target - candidates[u] * i);
            path.push_back(candidates[u]);
        }
        // 需要回溯恢复现场
        for (int i = 0; candidates[u] * i <= target; i++) {
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        if (candidates.size() == 0) {
            return res;
        }
        backtrackingII(candidates, 0, target);
        return res;
    }
};