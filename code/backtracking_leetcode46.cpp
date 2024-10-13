/*
 * @Author: Jean_Leung
 * @Date: 2024-10-13 17:43:26
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-13 18:25:21
 * @FilePath: \code\backtracking_leetcode46.cpp
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
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> permute(vector<int> &nums) {
        // 全排列
        if (nums.size() == 0) {
            return res;
        }
        vector<bool> used(nums.size(), false);
        dfs(nums, used);
        return res;
    }

    void dfs(vector<int> &nums, vector<bool> used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // true代表该位置已经用过
            if (used[i]) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            dfs(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
};