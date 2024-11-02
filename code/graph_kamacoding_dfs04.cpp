/*
 * @Author: Jean_Leung
 * @Date: 2024-10-30 11:30:52
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-30 11:30:59
 * @FilePath: \code\graph_kamacoding_dfs04.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

void dfs(vector<vector<int>> &grid, int x, int y) {
    // 将靠边的陆地改为2
    grid[x][y] = 2;
    for (int i = 0; i < 4; i++) {
        int next_x = x + dir[i][0];
        int next_y = y + dir[i][1];
        if (next_x < 0 || next_x >= grid.size() || next_y < 0 ||
            next_y >= grid[0].size()) {
            continue;
        }
        if (grid[next_x][next_y] == 0 || grid[next_x][next_y] == 2) {
            continue;
        }
        dfs(grid, next_x, next_y);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 1) {
            dfs(grid, i, 0);
        }
        if (grid[i][m - 1] == 1) {
            dfs(grid, i, m - 1);
        }
    }
    for (int j = 0; j < m; j++) {
        if (grid[0][j] == 1) {
            dfs(grid, 0, j);
        }
        if (grid[n - 1][j] == 1) {
            dfs(grid, n - 1, j);
        }
    }
    // 将孤岛变成0，将2变成1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                grid[i][j] = 0;
            }
            if (grid[i][j] == 2) {
                grid[i][j] = 1;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}