/*
 * @Author: Jean_Leung
 * @Date: 2024-10-14 10:51:51
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-14 12:12:01
 * @FilePath: \code\backtracking_leetcode332.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

/**
 * void backtracking(参数) {
        if (终⽌条件) {
            存放结果;
            return;
        }
        for (选择：本层集合中元素（树中节点孩⼦的数量就是集合的⼤⼩）) {
            处理节点;
            backtracking(路径，选择列表); // 递归
            回溯，撤销处理结果
        }
    }
 */

class Solution {
  public:
    vector<string> ans;
    // unordered_map<出发机场, map<到达机场, 航班次数>>
    // 记录到达的航班次数很重要,因为需要防止遍历过重复的航班航线
    unordered_map<string, map<string, int>> targets;
    // 法二:利用这个来做
    // unordered_map<出发机场, 到达机场的集合> targets
    // 且multiset默认是字典序进行排序了，基于红黑树的排序
    unordered_map<string, multiset<string>> uset;
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        // 先记录在targets上
        for (const vector<string> &vec : tickets) {
            targets[vec[0]][vec[1]]++; // 记录映射关系
        }
        vector<string> result;
        result.push_back("JFK");     // 起点确定
        dfs(tickets.size(), result); //
        return result;
    }

    // 这道题目难点在于如何构建映射
    // 如何判定终止条件
    // 如何进行单层逻辑
    bool dfs(int ticketnum, vector<string> &result) {
        // 如何确定终止条件
        if (result.size() == ticketnum + 1) {
            return true;
        }
        // 最难就是怎么确定遍历
        for (pair<const string, int> &target :
             targets[result[result.size() - 1]]) {
            if (target.second > 0) {
                result.push_back(target.first);
                target.second--;
                if (dfs(ticketnum, result)) {
                    return true;
                }
                target.second++;
                result.pop_back();
            }
        }
    }

    // Y神写法,求解欧拉路径的思路
    // 利用multiset来存储路径
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        for (auto &e : tickets) {
            // 这个代表往该地点的出发multiset里面插入数据
            uset[e[0]].insert(e[1]);
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void dfs(string u) {
        // 也就是当前的节点没有存在需要遍历的路径时候,就开始回溯
        while (uset[u].size()) {
            auto ver = *uset[u].begin();
            uset[u].erase(uset[u].begin());
            dfs(ver);
        }
        ans.push_back(u);
    }
};