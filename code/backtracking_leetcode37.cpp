/*
 * @Author: Jean_Leung
 * @Date: 2024-10-15 10:33:31
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-15 10:59:22
 * @FilePath: \code\backtracking_leetcode37.cpp
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
    void solveSudoku(vector<vector<char>> &board) { dfs(board); }

    bool dfs(vector<vector<char>> &board) {
        // 终止条件???
        // 这道题目适合返回布尔值
        // 因为递归到最后的叶子节点的时候,自动填满就会返回true
        // 因为这题需要整行都填满数字,所以我们需要双层for
        // 因为遍历节点就是先控制i后,控制j
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') {
                    continue;
                }
                for (char k = '1'; k <= '9'; k++) {
                    if (isValid(i, j, k, board)) {
                        board[i][j] = k;
                        if (dfs(board)) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                }
                return false; // 9个数都试玩，不行返回false
            }
        }
        return true;
    }

    // 判断当前要填的位置是否满足数独要求
    bool isValid(int row, int col, char val, vector<vector<char>> &board) {
        // 先判断行
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == val) {
                return false;
            }
        }
        // 再判断列
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == val) {
                return false;
            }
        }
        // 再判断九宫格
        int start_row = (row / 3) * 3;
        int start_col = (col / 3) * 3;
        for (int i = start_row; i < start_row + 3; i++) {
            for (int j = start_col; j < start_col + 3; j++) {
                if (board[i][j] == val) {
                    return false;
                }
            }
        }
        return true;
    }
};