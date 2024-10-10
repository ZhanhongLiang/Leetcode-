/*
 * @Author: Jean_Leung
 * @Date: 2024-10-10 13:42:34
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-10 15:16:00
 * @FilePath: \code\backtracking_leetcode77.cpp
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
    vector<int> path;        // 用来存放符合条件的结果
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return res;
    }
    // 处理节点
    /**
     * @description: 回溯算法,n是[1,n]的结尾,k是组合集合的个数
     * @param {int} n
     * @param {int} k
     * @param {int} start_index
     * @return {*}
     */
    void backtracking(int n, int k, int start_index) {
        // 需要添加到结果集合
        // 终止条件
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        // 遍历集合
        for (int i = start_index; i <= n; i++) {
            // 处理节点
            path.push_back(i);
            // 回溯,在当前开始的位置+1
            backtracking(n, k, i + 1);
            path.pop_back(); // 回溯
        }
    }
};