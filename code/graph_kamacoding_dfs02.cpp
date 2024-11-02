/*
 * @Author: Jean_Leung
 * @Date: 2024-10-28 14:17:57
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-28 14:41:25
 * @FilePath: \code\graph_kamacoding_dfs02.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

// 代表遍历方向
int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
int area; // 岛屿面积
void dfs(const vector<vector<int>> &grid, vector<vector<bool>> visited, int x,
         int y) {
    for (int i = 0; i < 4; i++) {
        int next_x = grid[x][y] + dir[i][0];
        int next_y = grid[x][y] + dir[i][1];
        if (next_x < 0 || next_x >= grid.size() || next_y < 0 ||
            next_y >= grid[0].size()) {
            continue;
        }
        if (!visited[next_x][next_y] && grid[next_x][next_y] == 1) {
            visited[next_x][next_y] = true;
            area++;
            dfs(grid, visited, next_x, next_y);
        }
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
    int res = 0; // 答案

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = true;
            area = 1;
            dfs(grid, visited, i, j);
            res = max(area, res);
        }
    }
    std::cout << res << std::endl;
}