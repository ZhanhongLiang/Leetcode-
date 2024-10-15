/*
 * @Author: Jean_Leung
 * @Date: 2024-10-15 09:48:01
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-15 10:28:50
 * @FilePath: \code\backtracking_leetcode51.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <map>
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
    vector<vector<string>> res; // 答案数组
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        std::vector<std::string> chessboard(n, std::string(n, '.'));
        dfs(n, 0, chessboard);
        return res;
    }

    void dfs(int n, int row, vector<string> &chess) {
        // 从代码随想录画的流程图可以知道
        // row是递归深度的体现,当row==n的时候，存进res中
        if (row == n) {
            res.push_back(chess);
            return;
        }
        for (int col = 0; col < n; col++) {
            // 需要判断当前的棋盘是否存在列行斜重合
            if (isValid(row, col, chess, n)) {
                chess[row][col] = 'Q';
                dfs(n, row + 1, chess);
                // 回溯
                chess[row][col] = '.';
            }
        }
    }

    bool isValid(int row, int col, vector<string> &chess, int n) {
        // 不用判断行，因为递归控制的每次放的行都是不一样的
        // 先判断列
        for (int i = 0; i < row; i++) {
            if (chess[i][col] == 'Q') {
                return false;
            }
        }
        // 检查45度是否存在皇后
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chess[i][j] = 'Q') {
                return false;
            }
        }
        // 检查135度是否存在皇后
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chess[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};