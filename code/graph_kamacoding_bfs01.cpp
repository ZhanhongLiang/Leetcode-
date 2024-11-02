#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

void bfs(const vector<vector<int>> &grid, vector<vector<bool>> &visited, int x,
         int y) {
    // bfs遍历
    // 节点队列,需要将图周围所有的节点加入队列中
    queue<pair<int, int>> que;
    que.push({x, y});
    visited[x][y] = true;
    while (!que.empty()) {
        pair<int, int> cur = que.front();
        que.pop();
        int cur_x = cur.first;
        int cur_y = cur.second;
        for (int i = 0; i < 4; i++) {
            int next_x = cur_x + dir[i][0];
            int next_y = cur_y + dir[i][1];
            if (next_x < 0 || next_x >= grid.size() || next_y < 0 ||
                next_y >= grid[0].size()) {
                continue;
            }
            if (!visited[next_x][next_y] && grid[next_x][next_y] == 1) {
                que.push({next_x, next_y});
                visited[next_x][next_y] = true;
            }
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
                res++;
                bfs(grid, visited, i, j);
            }
        }
    }
    std::cout << res << std::endl;
}
