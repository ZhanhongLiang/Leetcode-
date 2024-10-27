/*
 * @Author: Jean_Leung
 * @Date: 2024-10-27 20:53:59
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-27 21:51:32
 * @FilePath: \code\graph_leetcode797.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

/*
void dfs(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本节点所连接的其他节点) {
        处理节点;
        dfs(图，选择的节点); // 递归
        回溯，撤销处理结果
    }
}
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> result;
vector<int> path; // 用来存储经过的路径,只有满足一定条件才能放进res.push(path)
// graph输入的图
// x当前遍历的节点
// n图遍历的终点
void dfs(vector<vector<int>> &graph, int x, int n) {
    // 终止条件
    // 回顾回溯的框架
    // 当前遍历的节点如果为n的时候
    // 那么就到达终止条件
    if (x == n) {
        result.push_back(path);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (graph[x][i] == 1) {
            // 找到x指向的节点,就是节点i
            path.push_back(i);
            dfs(graph, i, n);
            path.pop_back(); // 回溯
        }
    }
}

int main() {
    // n 代表有n个节点
    // m代表有m条有向边，
    // s代表 有向边起点
    // t代表 有向边终点
    int n, m, s, t;
    cin >> n >> m;
    // 初始化图,有n个节点，都初始化为，边都初始化为0
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    // 需要初始化边
    while (m--) {
        cin >> s >> t;
        graph[s][t] = 1;
    }
    // 默认从1开始
    path.push_back(1);
    dfs(graph, 1, n);
    // 输出
    if (result.size() == 0) {
        cout << -1 << endl;
    }
    for (const vector<int> &pa : result) {
        for (int i = 0; i < pa.size() - 1; i++) {
            cout << pa[i] << " ";
        }
        cout << pa[pa.size() - 1] << endl;
    }
}

class Solution {
  public:
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        result.clear();
        if (graph.size() == 0) {
            return result;
        }
        path.push_back(0);
        dfs(graph, 0);
        return result;
    }

    // graph输入的图
    // x当前遍历的节点
    void dfs(vector<vector<int>> &graph, int x) {
        // 终止条件
        // 回顾回溯的框架
        // 当前遍历的节点如果为n的时候
        // 那么就到达终止条件
        if (x == graph.size() - 1) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < graph[x].size(); i++) {
            // 找到x指向的节点,就是节点i
            path.push_back(graph[x][i]);
            dfs(graph, graph[x][i]);
            path.pop_back(); // 回溯
        }
    }
};
