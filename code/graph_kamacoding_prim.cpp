/*
 * @Author: Jean_Leung
 * @Date: 2024-11-03 13:21:27
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-11-03 14:23:29
 * @FilePath: \code\graph_kamacoding_prim.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

/**
 * prim算法核心就是三步，我称为**prim三部曲**，大家一定要熟悉这三步，代码相对会好些很多：
1. 第一步，选距离生成树最近节点
2. 第二步，最近节点加入生成树
3. 第三步，更新非生成树节点到生成树的距离（即更新minDist数组）
minDist数组 用来记录 每一个节点距离最小生成树的最近距离
总结来说，prim算法是点优先算法
 */

int main() {
    // v代表顶点数
    // e代表边数
    // x 代表起点
    // y代表终点
    // k代表x->y的边权值
    int v, e;
    int x, y, k;
    cin >> v >> e;
    // 用邻接矩阵来表示该图
    // 边权值最大为10000
    vector<vector<int>> grid(v + 1, vector<int>(v + 1, 10001));
    // 因为邻接矩阵具有对称性
    while (e--) {
        cin >> x >> y >> k;
        grid[x][y] = k;
        grid[y][x] = k;
    }
    // 所有节点到最小生成树的最小距离
    vector<int> minDist(v + 1, 10001);
    // 判断这个节点是否在生成树
    vector<bool> is_in_tree(v + 1, false);

    // 加上初始化
    // 这个是描述出最小生成树的边的数组
    // parent[j] = cur
    // 就是指出最小生成树中j-cur中的边
    vector<int> parent(v + 1, -1);

    // 需要循环v-1次，因为最小生成树有v-1条边
    for (int i = 1; i < v; i++) {
        // prim三部曲
        // 第一步,选距离生成树最近节点
        int cur = -1; // 选中的节点
        // 记录距离该生成树的其余节点的最短距离
        int min_value = INT_MAX;
        // 从1开始遍历, 遍历到v节点
        for (int j = 1; j <= v; j++) {
            //  选取最小生成树节点的条件：
            //  （1）不在最小生成树里
            //  （2）距离最小生成树最近的节点
            if (!is_in_tree[j] && minDist[j] < min_value) {
                min_value = minDist[j];
                cur = j;
            }
        }
        // 2、prim三部曲，第二步：最近节点（cur）加入生成树
        is_in_tree[cur] = true;
        // 3、prim三部曲，第三步：更新非生成树节点到生成树的距离（即更新minDist数组）
        // cur节点加入之后， 最小生成树加入了新的节点，那么所有节点到
        // 最小生成树的距离（即minDist数组）需要更新一下
        // 由于cur节点是新加入到最小生成树，那么只需要关心与 cur 相连的
        // 非生成树节点 的距离 是否比 原来
        // 非生成树节点到生成树节点的距离更小了呢
        for (int j = 1; j <= v; j++) {
            if (!is_in_tree[j] && grid[cur][j] < minDist[j]) {
                minDist[j] = grid[cur][j];
                parent[j] = cur;
            }
        }
    }
    // 统计结果
    int result = 0;
    // 不计第一个顶点，因为统计的是边的权值，v个节点有 v-1条边
    for (int i = 2; i <= v; i++) {
        result += minDist[i];
    }
    // 打印出最小生成树
    for (int i = 1; i <= v; i++) {
        cout << i << "->" << parent[i] << endl;
    }
    cout << result << endl;
}