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
        if (grid[x][y] > grid[next_x][next_y]) {
            continue;
        }
        dfs(grid, visited, next_x, next_y);
    }
    return;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<bool>> first_border(n, vector<bool>(m, false));
    vector<vector<bool>> second_border(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    // 需要从左右边界开始遍历
    for (int i = 0; i < n; i++) {
        dfs(grid, first_border, i, 0);
        dfs(grid, second_border, i, m - 1);
    }
    // 从上下边界开始
    for (int j = 0; j < m; j++) {
        dfs(grid, first_border, 0, j);
        dfs(grid, second_border, n - 1, j);
    }
    // 只要同时满足first_border 和 second_border同时访问过
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (first_border[i][j] && second_border[i][j]) {
                std::cout << i << " " << j << std::endl;
            }
        }
    }
}