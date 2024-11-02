/*
 * @Author: Jean_Leung
 * @Date: 2024-11-02 14:31:37
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-11-02 16:42:07
 * @FilePath: \code\graph_kamacoding_redundancy_connection.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

int n; // 结点数和边数
vector<int> parent = vector<int>(1001, 0);

void init() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

// 寻找该节点的根节点
// 路径压缩
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// 合并
void unionSets(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);
    if (root_x == root_y) {
        return;
    }
    parent[root_y] = root_x;
}

// 判断是否同根
bool isSame(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);
    return root_x == root_y;
}

int main() {
    int s, t;
    cin >> n;
    init();
    while (n--) {
        cin >> s >> t;
        if (isSame(s, t)) {
            cout << s << " " << t << endl;
            return 0;
        } else {
            unionSets(s, t);
        }
    }
}
