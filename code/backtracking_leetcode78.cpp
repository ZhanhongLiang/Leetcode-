/*
 * @Author: Jean_Leung
 * @Date: 2024-10-13 15:13:07
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-13 16:45:36
 * @FilePath: \code\backtracking_leetcode78.cpp
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
    vector<vector<int>> res; // 总包含一个空集
    vector<int> path;
    vector<vector<int>> subsets(vector<int> &nums) {
        if (nums.size() == 0) {
            return res;
        }
        // res.push_back({});
        dfs(nums, 0);
        return res;
    }
    // 这道题和回文字串很相似
    void dfs(vector<int> &nums, int start_index) {
        // 无论如何都要添加子集,不需要满足才添加
        res.push_back(path);
        if (start_index >= nums.size()) {
            return;
        }
        // for
        for (int i = start_index; i < nums.size(); i++) {
            // 需要像字符串那种给分割出来
            // vector<int> temp(nums.begin() + start_index, nums.begin() + i);
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }
};