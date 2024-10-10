/*
 * @Author: Jean_Leung
 * @Date: 2024-10-10 15:15:34
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-10 19:10:06
 * @FilePath: \code\backtracking_leetcode17.cpp
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

const string lettermap[10] = {"",    "",    "abc", "def", "ghi",
                              "jkl", "mno", "pqr", "stu", "vwyz"};

class Solution {
  public:
    vector<string> res;
    // unordered_map<int, string> hash_map; // 存放号码与字符串的映射
    string path;
    // 代表j
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return res;
        }
        backtracking(digits, 0);
        return res;
    }
    // layer代表digits某层
    void backtracking(string digits, int layer) {
        // 终止条件
        if (path.size() == digits.size()) {
            res.push_back(path);
            return;
        }
        int digit = digits[layer] - '0';  // 转换为int
        string letter = lettermap[digit]; // 获得字符串
        for (int i = 0; i < letter.size(); i++) {
            path.push_back(letter[i]);
            backtracking(digits, layer + 1);
            path.pop_back();
            // path.erase()
            // path.erase(path.begin()+)
        }
    }

    /**
     * @description:回溯第二种写法
     * @param {string} digits
     * @param {int} layer
     * @param {string} path_
     * @return {*}
     */
    void backtrackingII(string digits, int layer, string path_) {
        if (path.size() == digits.size()) {
            res.push_back(path);
            return;
        }
        int digit = digits[layer] - '0';
        string letter = lettermap[digit]; // 获得字符串
        for (int i = 0; i < letter.size(); i++) {
            backtrackingII(digits, layer + 1, path_ + letter[i]);
        }
    }
};