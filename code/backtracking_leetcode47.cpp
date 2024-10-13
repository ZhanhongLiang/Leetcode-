/*
 * @Author: Jean_Leung
 * @Date: 2024-10-13 18:27:05
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-13 18:42:20
 * @FilePath: \code\backtracking_leetcode47.cpp
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
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        if (nums.size() == 0) {
            return ans;
        }
        vector<bool> used(nums.size(), false);
        dfs(nums, used);
        return ans;
    }

    void dfs(vector<int> &nums, vector<bool> used) {
        // 需要用set来判断每个树层的去重
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        unordered_set<int> uset;
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] || uset.find(nums[i]) != uset.end()) {
                continue;
            }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            used[i] = true;
            dfs(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
};