/*
 * @Author: Jean_Leung
 * @Date: 2024-10-11 14:03:55
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-11 15:00:06
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
        dfs(s,0);
        return res;
    }
    bool isPalindrome(string str, int start, int end) {
        // 串是否为空
        // if (str.empty()) {
        //     return false;
        // }
        for (int left = start, right = end; left <= right; left++, right--) {
            if (str[left] != str[right]) {
                return false;
            }
        }
        return true;
    }

    // 如何进行截取,
    void dfs(string s, int start_index) {
        // 终止条件
        if (start_index >= s.size()) {
            res.push_back(path);
            return;
        }
        // for循环
        for (int i = start_index; i < s.size(); i++) {
            // 需要将path添加字符
            // 进行剪枝
            // 当前节点层的遍历中，从start_index开始位置到i位置是否是回文串
            if (isPalindrome(s, start_index, i)) {
                // 切割出来子字符串
                // 获取[startIndex,i]在s中的⼦串
                // i-start_index+1是长度
                string temp = s.substr(start_index, i - start_index + 1);
                path.push_back(temp);
            } else {
                continue;
            }
            dfs(s, i + 1); // 继续遍历下个位置
            path.pop_back();
        }
    }
};