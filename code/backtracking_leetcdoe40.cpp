/*
 * @Author: Jean_Leung
 * @Date: 2024-10-10 20:06:09
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-11 14:03:13
 * @FilePath: \code\backtracking_leetcdoe40.cpp
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
    vector<vector<int>> res;
    vector<int> path;
    int sum = 0;
    // vector<bool> used; // 标签同一个树层是否有遍历过
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<bool> used(candidates.size(), false);
        if (candidates.size() == 0) {
            return res;
        }
        // 需要先排序，因为这样可以让相同元素挨在一起
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, used);
        return res;
    }

    void backtracking(vector<int> &candidates, int target, int start_index,
                      vector<bool> used) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            res.push_back(path);
            return;
        }
        for (int i = start_index;
             i < candidates.size() && sum + candidates[i] <= target; i++) {
            // used是尝试访问的节点
            // used[i - 1] == true，说明同⼀树枝candidates[i - 1]使⽤过
            // used[i - 1] == false，说明同⼀树层candidates[i - 1]使⽤过
            // 要对同⼀树层使⽤过的元素进⾏跳过
            if (i > 0 && candidates[i] == candidates[i - 1] &&
                used[i - 1] == false) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            // i+1的意思就是每个数字在每个组合中只能使用一次
            backtracking(candidates, target, i + 1, used);
            used[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
    }

    // 这种写法是y神的写法，但是不太容易理解
    void backtrackingII(vector<int> &candidates, int u, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        // 当前遍历的的下标是数组长度时候,那么就会进行返回
        if (u == candidates.size()) {
            return;
        }
        // 开始遍历
        for (int i = 0; candidates[u] * i <= target; i++) {
            backtrackingII(candidates, u + 1, target - candidates[u] * i);
            path.push_back(candidates[u]);
        }
        // 恢复现场
        for (int i = 0; candidates[u] * i <= target; i++) {
            path.pop_back();
        }
    }
};