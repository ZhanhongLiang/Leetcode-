/*
 * @Author: Jean_Leung
 * @Date: 2024-10-13 15:35:52
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-13 16:38:23
 * @FilePath: \code\backtracking_leetcode90.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

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

class Solution {
  public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<bool> used(nums.size(), false);
        if (nums.size() == 0) {
            return res;
        }
        sort(nums.begin(), nums.end()); // 需要先排序
        dfs(nums, 0, used);
        return res;
    }

    void dfs(vector<int> &nums, int start_index, vector<bool> &used) {
        // 需要判断是否重合
        res.push_back(path);
        if (start_index >= nums.size()) {
            return;
        }
        for (int i = start_index; i < nums.size(); i++) {
            // 需要判断是否是重复的
            // 这题关键在于怎么判断分割的数据集是否重复
            // 这道题和前面leetcode40组合总和很相似
            // 还是一样，需要判断同一个树层是否满足
            // used[i - 1] == true，说明同⼀树枝candidates[i - 1]使⽤过
            // used[i - 1] == false，说明同⼀树层candidates[i - 1]使⽤过
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true; // 代表同一个数枝条使用过
            dfs(nums, i + 1, used);
            used[i] = false; // 代表同一层使用过
            path.pop_back();
        }
    }
};