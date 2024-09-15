/*
 * @Author: Jean_Leung
 * @Date: 2024-09-13 22:49:37
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-13 23:22:20
 * @FilePath: \code\rotate_matrix_leetcode54.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

class Solution {
  public:
    //
    // (0,0)  一 一 一 一 一 一>y
    //       |
    //       |
    //       |
    //       |
    //       v
    //       x
    // AC-WINGS Y神写法
    // dx[]规定了x方向的，如果向右走,那么x值不会变, 如果向下走，那么x值递增
    // 如果向左走，那么x值不变，如果向上走，那么x值递减
    // dx[]={0,1,0,-1}
    // d代表当前方向
    // a = x+dx[d], a代表着x方向的坐标
    // dy[]规定了y方向的
    // dy[]规定了y方向的，如果向右走,那么y值递增, 如果向下走，那么y值不变
    // 如果向左走，那么y值递减，如果向左走，那么y值不变
    // dy[]={1,0,-1,0}
    // b = y+dy[d],b代表着y方向的坐标
    vector<int> generateMatrix(vector<vector<int>> matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res(n * m, 0); // 结果矩阵
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        vector<vector<bool>> st(m, vector<bool>(n));
        // i代表着总共走的步数
        for (int i = 0, x = 0, y = 0, d = 0; i < m * n; i++) {
            // 更新result值
            // res[i - 1] = matrix[x][y];
            res.push_back(matrix[x][y]);
            st[x][y] = true; // 记录遍历的状态
            int a = x + dx[d];
            int b = y + dy[d]; // a代表目前的x方向坐标,b代表目前方向的y坐标
            if (a < 0 || a >= m || b < 0 || b >= n || st[x][y]) {
                d = (d + 1) % 4; // 更新方向
                a = x + dx[d], b = y + dy[d];
            }
            x = a;
            y = b;
        }
        return res;
    }

    vector<vector<int>> generateMatrixII(int n) {
        vector<vector<int>> result(n,
                                   vector<int>(n, 0)); // 这个是返回的矩阵形状
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        // i代表着总共走的步数
        for (int i = 1, x = 0, y = 0, d = 0; i <= n * n; i++) {
            // 更新result值
            result[x][y] = i;
            int a = x + dx[d];
            int b = y + dy[d]; // a代表目前的x方向坐标,b代表目前方向的y坐标
            if (a < 0 || a >= n || b < 0 || b >= n || result[a][b]) {
                d = (d + 1) % 4; // 更新方向
                a = x + dx[d], b = y + dy[d];
            }
            x = a;
            y = b;
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    // vector<int> test_nums{0, 1, 2, 3, 3, 0, 4, 2};
    // int n = 5, m = 6;
    // vector<vector<int>> matrix(m, vector<int>(n, 0));
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         matrix[i][j] = j+1;
    //     }
    // }
    // vector<vector<int>> ans = solution.generateMatrix(n);
    // std::cout << "ans:" << ans << std::endl;
    vector<vector<int>> test_matrix = solution.generateMatrixII(3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << test_matrix[i][j] << " ";
        }
        std::cout << endl;
    }
    std::cout << endl;
    vector<int> ans = solution.generateMatrix(test_matrix);
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " ";
    }
    return 0;
}
