#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// key代表当前遍历的节点
// visited代表是否有遍历过
void dfs(const vector<list<int>> &graph, int key, vector<bool> &visited) {
    // 这道题就是dfs的方法
    // 这道题是有向图，不是第一题的无向图
    // 回溯三部曲
    // 终止条件
    if (visited[key]) {
        return;
    }
    // 寻找节点
    visited[key] = true;
    // 需要用链表存储?
    // 这道题储存用的是邻接表，
    // 并不是用邻接矩阵
    // list<int> 是 C++ STL
    // 中的一个`双向链表容器`，适合于频繁的插入和删除操作。以下是 list<int>
    list<int> keys = graph[key];
    for (int key : keys) {
        // 继续深搜
        dfs(graph, key, visited);
    }
}

int main() {
    // n 代表点数
    //  m代表边数
    //  s代表开始指向方向
    int n, m, s, t;
    cin >> n >> m;
    // 节点编号从1到n，所以申请 n+1 这么大的数组
    vector<list<int>> graph(n + 1);
    // 先将vector的数组进行定义先
    // 然后在初始化边表
    while (m--) {
        cin >> s >> t;
        // 点表为s，s->t，所以将t放置在边表中
        graph[s].push_back(t);
    }
    vector<bool> visited(n + 1, false);
    dfs(graph, 1, visited);
    // 检查是否都能走
    for (int i = 1; i <= n; i++) {
        if (visited[i] == false) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
}