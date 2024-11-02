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
        // 这个规定了
    }
}