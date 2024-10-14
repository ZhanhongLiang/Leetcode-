/*
 * @Author: Jean_Leung
 * @Date: 2024-10-13 15:35:52
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-14 13:07:58
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
        if (nums.size() == 0) {
            return res;
        }
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, 0, used);
        return res;
    }

    void dfs(vector<int> &nums, int start_index, vector<bool> used) {
        // used数组代表是否有访问过该数
        res.push_back(path);
        if (start_index >= nums.size()) {
            return;
        }
        for (int i = start_index; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            // 如果当前
            path.push_back(nums[i]);
            used[i] = true;
            dfs(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }
};