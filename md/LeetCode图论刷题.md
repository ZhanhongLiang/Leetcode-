# 797 [所有可能到达的路径](https://leetcode.cn/problems/all-paths-from-source-to-target/description/)

## 题目

给你一个有 `n` 个节点的 **有向无环图（DAG）**，请你找出所有从节点 `0` 到节点 `n-1` 的路径并输出（**不要求按特定顺序**）

 `graph[i]` 是一个从节点 `i` 可以访问的所有节点的列表（即从节点 `i` 到节点 `graph[i][j]`存在一条有向边）。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/09/28/all_1.jpg)

```
输入：graph = [[1,2],[3],[3],[]]
输出：[[0,1,3],[0,2,3]]
解释：有两条路径 0 -> 1 -> 3 和 0 -> 2 -> 3
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2020/09/28/all_2.jpg)

```
输入：graph = [[4,3,1],[3,2,4],[3],[4],[]]
输出：[[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
```

 

**提示：**

- `n == graph.length`
- `2 <= n <= 15`
- `0 <= graph[i][j] < n`
- `graph[i][j] != i`（即不存在自环）
- `graph[i]` 中的所有元素 **互不相同**
- 保证输入为 **有向无环图（DAG）**

## 题目大意

>从节点0到节点n-1输出所有可以到达的路径,`注意给的图不一定是强连通图`

## 解题思路

- 此题是dfs的模板题，用来练手的，一定要掌握

```c++
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
```



## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-10-27 20:53:59
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-27 21:42:57
 * @FilePath: \code\graph_leetcode797.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
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

// acm模式
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

// leetcode提交
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

```



# [岛屿数量](https://kamacoder.com/problempage.php?pid=1171)

## 题目

**题目描述**

给定一个由 1（陆地）和 0（水）组成的矩阵，你需要计算岛屿的数量。岛屿由水平方向或垂直方向上相邻的陆地连接而成，并且四周都是水域。你可以假设矩阵外均被水包围。

**输入描述**

第一行包含两个整数 N, M，表示矩阵的行数和列数。

后续 N 行，每行包含 M 个数字，数字为 1 或者 0。

**输出描述**

输出一个整数，表示岛屿的数量。如果不存在岛屿，则输出 0。

**输入示例**

```
4 5
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1
```

**输出示例**

```
3
```

**提示信息**

![img](https://kamacoder.com/upload/kamacoder.com/image/20240411/20240411153209_67737.png)

根据测试案例中所展示，岛屿数量共有 3 个，所以输出 3。



**数据范围：**

1 <= N, M <= 50

## 题目大意



## 解题思路



## 代码

