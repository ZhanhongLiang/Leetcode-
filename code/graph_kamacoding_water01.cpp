/*
 * @Author: Jean_Leung
 * @Date: 2024-10-30 17:20:07
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-30 17:57:58
 * @FilePath: \code\graph_kamacoding_water01.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

void dfs(const vector<vector<int>> &grid, vector<vector<bool>> &visited, int x,
         int y) {
    // 如果当前遍历过
    if (visited[x][y]) {
        return;
    }
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int next_x = x + dir[i][0];
        int next_y = y + dir[i][1];
        if (next_x < 0 || next_x >= grid.size() || next_y < 0 ||
            next_y >= grid[x].size()) {
            continue;
        }
        // 如果当前的{x,y}位置的值比{next_x,next_y}的值大，或者相等
        // 就可以继续遍历
        if (grid[x][y] < grid[next_x][next_y]) {
            continue;
        }
        dfs(grid, visited, next_x, next_y);
    }
    return;
}

// 需要判断每个节点是否能到达第一边界和第二边界
bool isArraival(const vector<vector<int>> &grid, int x, int y) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    dfs(grid, visited, x, y);
    bool isFirst = false;
    bool isSecond = false;
    // 先判断第一边界的上界
    for (int j = 0; j < m; j++) {
        if (visited[0][j]) {
            isFirst = true;
            break;
        }
    }
    // 再判断第一边界的左界
    for (int i = 0; i < n; i++) {
        if (visited[i][0]) {
            isFirst = true;
            break;
        }
    }
    // 判断第二边界的右界
    for (int i = 0; i < n; i++) {
        if (visited[i][m - 1]) {
            isSecond = true;
            break;
        }
    }
    // 判断第二边界的下界
    for (int j = 0; j < m; j++) {
        if (visited[n - 1][j]) {
            isSecond = true;
            break;
        }
    }
    return isFirst && isSecond;
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
    // vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isArraival(grid, i, j)) {
                cout << i << " " << j << endl;
            }
        }
    }
}