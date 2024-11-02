/*
 * @Author: Jean_Leung
 * @Date: 2024-10-30 10:41:46
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-30 11:09:30
 * @FilePath: \code\graph_kamacoding_dfs03.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
int count = 0; // 孤岛面积
// 需要将不靠近边界的陆地变成海洋
//    也就是grid[i][0] 和grid[i][grid[0].size()- 1]开始将陆地变成海洋,也就是两边
//    再从上下边将陆地变成海洋
void dfs(vector<vector<int>> &grid, int x, int y) {
    grid[x][y] = 0;
    count++;
    // 图论深搜
    for (int i = 0; i < 4; i++) {
        // 判断下一个位置
        int next_x = x + dir[i][0];
        int next_y = y + dir[i][1];
        // 如果下一个访问过，或者越界需要continue
        if (next_x < 0 || next_x >= grid.size() || next_y < 0 ||
            next_y >= grid[0].size()) {
            continue;
        }
        // 假如这里不是海洋，那么就需要重新遍历
        if (grid[next_x][next_y] == 0) {
            continue;
        }
        // 否则直接dfs
        // 需要判断next_x和next_y不碰到边界
        // if (grid[next_x][next_y] == 1 && !visited[next_x][next_y]) {
        //     dfs(grid, visited, next_x, next_y);
        // }
        dfs(grid, next_x, next_y);
    }
}

int main() {
    // 行列数
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    // 需要先消除边的陆地，将其变成海洋
    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 1) {
            dfs(grid, i, 0);
        }
        if (grid[i][m - 1] == 1) {
            dfs(grid, i, m - 1);
        }
    }

    // 上下边
    for (int j = 0; j < m; j++) {
        if (grid[0][j] == 1) {
            dfs(grid, 0, j);
        }
        if (grid[n - 1][j] == 1) {
            dfs(grid, n - 1, j);
        }
    }
    count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                dfs(grid, i, j);
            }
        }
    }
    std::cout << count << std::endl;
}