
// 版本一
#include <iostream>
#include <vector>
using namespace std;

// x方向，y方向
int dir[4][2] = {0, 1, 1, 0, -1, 0, 0 - 1}; // 代表遍历的四个方向

void dfs(const vector<vector<int>> &grid, vector<vector<bool>> &visited, int x,
         int y) {
    // x代表x方向，y代表y反向
    // 代表深搜的思路,沿着给定初始x,y坐标的周围四个方向进行深搜
    for (int i = 0; i < 4; i++) {
        int next_x = x + dir[i][0];
        int next_y = y + dir[i][1];
        if (next_x < 0 || next_x >= grid.size() || next_y < 0 ||
            next_y >= grid[0].size()) {
            continue;
        }
        if (!visited[next_x][next_y] && grid[next_x][next_y] == 1) {
            visited[next_x][next_y] = true;
            dfs(grid, visited, next_x, next_y);
        }
    }
}

int main() {
    int n, m;
    // n行数
    // m列数
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                visited[i][j] = true;
                res++;
                dfs(grid, visited, i, j);
            }
        }
    }
    std::cout << res << std::endl;
}