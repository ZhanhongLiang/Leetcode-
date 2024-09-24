/*
 * @Author: Jean_Leung
 * @Date: 2024-09-24 20:02:07
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-24 20:46:01
 * @FilePath: \code\stack_queue_leetcode347.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    // 按照value降序进行排序
    return a.second > b.second;
}
class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> ans;
        unordered_map<int, int> hash_map; // 用来统计数组中各个出现的字符数
        for (auto x : nums) {
            hash_map[x]++;
        }
        vector<pair<int, int>> vec(hash_map.begin(), hash_map.end());
        sort(vec.begin(), vec.end(), cmp);
        // 按照种类进行插入
        // auto it = hash_map.begin();
        for (int i = 0; i < k; i++) {
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> test{1, 1, 1, 2, 2, 3};
    vector<int> ans = solution.topKFrequent(test, 3);
    for (auto x : ans) {
        std::cout << x << "\n";
    }
    std::cout << std::endl;
}