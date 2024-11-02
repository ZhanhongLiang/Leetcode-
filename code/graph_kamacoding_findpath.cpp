/*
 * @Author: Jean_Leung
 * @Date: 2024-11-02 13:34:24
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-11-02 13:35:10
 * @FilePath: \code\graph_kamacoding_findpath.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */
#include <iostream>
#include <vector>

using namespace std;
// 两个节点在不在一个集合，也可以将两个节点添加到一个集合中

// 这道题考察的是并查集问题

// 节点数量
int n;
// 并查集储存
vector<int> parent = vector<int>(101, 0);

// 初始化
void init() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

// 查找某个节点的根节点
// 需要路径压缩优化
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // 这里路径压缩了
    }
    return parent[x];
}

// 判断x和y是否是同一个根
bool isSame(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);
    return root_x == root_y;
}

// 合并操作
void unionSets(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);
    if (root_x == root_y) {
        return;
    }
    parent[root_y] = root_x;
}

int main() {
    int m, s, t;
    int source, destination;
    cin >> n >> m;
    init();
    while (m--) {
        cin >> s >> t;
        unionSets(s, t);
    }
    cin >> source >> destination;
    if (isSame(source, destination)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
}
