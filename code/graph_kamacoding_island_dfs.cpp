#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
int count = 0;
void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y,
         int mark) {
    // 如果访问过就退出循环
    if (visited[x][y] || grid[x][y] == 0) {
        return;
    }
    // 将对应的岛屿标记编号
    grid[x][y] = mark;
    // 是否访问过
    visited[x][y] = true;
    count++;
    for (int i = 0; i < 4; i++) {
        int next_x = x + dir[i][0];
        int next_y = y + dir[i][1];
        if (next_x < 0 || next_x >= grid.size() || next_y < 0 ||
            next_y >= grid[0].size()) {
            continue;
        }
        // if (grid[next_x][next_y] == 0) {
        //     continue;
        // }
        dfs(grid, visited, next_x, next_y, mark);
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
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int mark = 2; // 编号
    // {编号: 面积}
    unordered_map<int, int> gridNum;
    // 标记是否全是陆地
    bool is_allisland = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                is_allisland = false;
            }
            if (!visited[i][j] && grid[i][j] == 1) {
                // 每次岛屿面积都要初始化为0
                count = 0;
                dfs(grid, visited, i, j, mark);
                gridNum[mark] = count;
                mark++;
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // 如果全是陆地，那么返回整块陆地面积
    if (is_allisland) {
        cout << n * m << endl;
        return 0;
    }
    // 使用unordered_set
    // 因为可以去重
    // 表示访问过的岛屿
    int result = 0;
    unordered_set<int> visited_island;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            count = 1; // 表示填海的面积
            // 表示已经访问过
            visited_island.clear(); // 需要清空
            if (grid[i][j] == 0) {
                // 也要从该陆地四周开始寻找填的岛屿
                for (int k = 0; k < 4; k++) {
                    int next_i = i + dir[k][0];
                    int next_j = j + dir[k][1];
                    if (next_i < 0 || next_i >= n || next_j < 0 ||
                        next_j >= m) {
                        continue;
                    }
                    // 去重重复添加的岛屿
                    // 如果找到重复的岛屿,那么就要继续寻找
                    if (visited_island.count(grid[next_i][next_j])) {
                        continue;
                    }
                    count += gridNum[grid[next_i][next_j]];
                    // 将其添加到visited_island里面，表示已经连接的岛屿
                    visited_island.insert(grid[next_i][next_j]);
                }
            }
            // 找到最大result
            result = max(result, count);
        }
    }
    cout << result << endl;
}
