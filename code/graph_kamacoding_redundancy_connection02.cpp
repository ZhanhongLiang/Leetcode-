/*
 * @Author: Jean_Leung
 * @Date: 2024-11-02 14:48:01
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-11-02 16:40:35
 * @FilePath: \code\graph_kamacoding_redundancy_connection02.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

// 有向树，除了根节点，每个节点只有一个父亲节点
// 根节点是没有父亲节点的
int n; // 代表节点和边数
vector<int> parent = vector<int>(1001, 0);

// 初始化
void init() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

// 查找
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

// 删除最后一条边
// 判断是否是有向树
bool isTreeAfterRemoveEdge(const vector<vector<int>> &edges, int delet_edge) {
    init();
    // 需要用并查集进行构建树,然后判断删除这条边后是否是有向树
    for (int i = 0; i < n; i++) {
        // 如果当前遍历边表的i等于要删除的边
        // 那么就需要跳过改变
        if (i == delet_edge) {
            continue;
        }
        // 跳过后进行判断
        // 如果发现某条边添加的时候是同根的,就证明存在环
        if (isSame(edges[i][0], edges[i][1])) {
            return false;
        }
        // 否则添加到并查集中
        unionSets(edges[i][0], edges[i][1]);
    }
    return true;
}

// 找到构建的时候最后出现的边
// 根据并查集的特性，当最后一个边
void getRemoveEdge(const vector<vector<int>> &edges) {
    init();
    for (int i = 0; i < n; i++) {
        if (isSame(edges[i][0], edges[i][1])) {
            cout << edges[i][0] << " " << edges[i][1] << endl;
            return;
        }
        unionSets(edges[i][0], edges[i][1]);
    }
}

// 删除某条边后判断是否还是有向树

int main() {
    int s, t;
    // 记录边表
    // 0位置是起始
    // 1位置是终点
    vector<vector<int>> edges;
    // 记录每个节点的入度
    // 因为从1开始，所以空间是要n+1
    vector<int> in_degree(n + 1, 0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        in_degree[t]++;
        edges.push_back({s, t});
    }

    // 边表已经储存好
    // 必须逆序遍历边表，找出入度为2的节点,
    // 如果是顺序的的，就不能保证一定删除就是最后一条出现的边了
    // 第一条边必然是最后出现的边
    // 第二条边是首先出现的边
    vector<int> vec; // 记录入度为2的边
    for (int i = n - 1; i >= 0; i++) {
        // 这里必须是要s>t，以t来找入度
        // i就代表是edges中哪一条边
        if (in_degree[edges[i][1]] == 2) {
            vec.push_back(i);
        }
    }
    // 需要分出两种情况,假如是存在入度==2的节点
    // 那么就要判断删除最后一条边是否满足该树是有向树的性质
    if (vec.size() > 0) {
        if (isTreeAfterRemoveEdge(edges, vec[0])) {
            cout << edges[vec[0]][0] << " " << edges[vec[0]][1] << endl;
        } else {
            cout << edges[vec[1]][0] << " " << edges[vec[1]][1] << endl;
        }
    }
    // 再判断第三种情况，如果不存在入度2，那么就说明图是存在环的
    // 需要删除存在环的最后一个边
    getRemoveEdge(edges);
}