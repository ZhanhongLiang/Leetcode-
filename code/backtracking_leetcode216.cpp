/*
 * @Author: Jean_Leung
 * @Date: 2024-10-10 14:49:14
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-10 15:05:21
 * @FilePath: \code\backtracking_leetcode216.cpp
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
    int sum = 0; // 和
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1);
        return res;
    }

    void backtracking(int k, int n, int start_index) {
        // 终止条件
        if (path.size() == k && sum == n) {
            res.push_back(path);
            return;
        }
        // for循环遍历集合
        for (int i = start_index; i <= 9; i++) {
            // 处理节点
            sum += i;
            path.push_back(i);
            backtracking(k, n, i + 1);
            path.pop_back(); // 回溯操作
            sum -= i;        // 回溯
        }
    }
};