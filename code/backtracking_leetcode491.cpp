/*
 * @Author: Jean_Leung
 * @Date: 2024-10-13 16:47:25
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-13 17:38:45
 * @FilePath: \code\backtracking_leetcode491.cpp
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
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        if (nums.size() == 0) {
            return ans;
        }
        vector<bool> used(nums.size(), false);
        dfs(nums, 0);
        // set<vector<int>> unique_set(ans.begin(), ans.end());
        // vector<vector<int>> unique_ans(unique_set.begin(), unique_set.end());
        return ans;
    }
    // path_size记录当前子集的数量,保证子集里面数量必须大于等于2
    void dfs(vector<int> &nums, int start_index) {
        if (path.size() > 1) {
            ans.push_back(path);
        }
        if (start_index >= nums.size()) {
            return;
        }
        // for
        // set是该层的去重，并不是迭代的去重
        unordered_set<int> unique_set;
        // find函数，如果找到返回指向该元素的迭代器
        // 如果没找到返回end()迭代器
        for (int i = start_index; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back()) ||
                unique_set.find(nums[i]) != unique_set.end()) {
                continue;
            }
            unique_set.insert(nums[i]);
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }

    // 需要额外判断一个数组是否有序吗?
    bool isSort(vector<int> path) {
        if (path.size() == 0) {
            return true;
        }
        for (int i = 0; i < path.size(); i++) {
            if (i > 0 && path[i] < path[i - 1]) {
                return false;
            }
        }
        return true;
    }
};