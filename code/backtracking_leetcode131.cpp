/*
 * @Author: Jean_Leung
 * @Date: 2024-10-11 14:03:55
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-13 14:49:51
 * @FilePath: \code\backtracking_leetcode131.cpp
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
    // 判断一个字符串是否是回文串
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<string>> partition(string s) {
        if (s.size() == 0) {
            return res;
        }
        dfs(s, 0);
        return res;
    }
    void dfs(string &s, int start_index) {
        // 需要使用剪枝
        if (start_index == s.size()) {
            res.push_back(path);
            return;
        }
        // 循环
        for (int i = start_index; i < s.size(); i++) {
            // 如果是回文子串
            if (isPandrome(s, start_index, i)) {
                path.push_back(s.substr(start_index, i - start_index + 1));
            } else {
                continue;
            }
            dfs(s, i + 1);
            path.pop_back();
        }
    }

    bool isPandrome(const string &s, int start, int end) {
        if (s.size() == 0) {
            return false;
        }
        for (int i = start; i <= end; i++) {
            if (s[start] != s[end]) {
                return false;
            }
        }
        return true;
    }
};