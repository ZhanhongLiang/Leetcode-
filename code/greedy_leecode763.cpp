/*
 * @Author: Jean_Leung
 * @Date: 2024-10-18 11:20:15
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-18 11:55:39
 * @FilePath: \code\greedy_leecode763.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <list>
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

// 尽可能多划分字符串
class Solution {
  public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        result.clear();
        if (s.size() == 0) {
            return result;
        }
        // 如果不用哈希表,
        // 初始化,s[i]-'a' 是属于0~27之间
        int hash[27] = {0};
        // 记录每个字符的最远出现位置
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a'] = i;
        }
        // 定义滑动窗口位置
        // 就是通过滑动窗口来分辨出分割的区间
        for (int i = 0, left = 0, right = 0; i < s.size(); i++) {
            // 找到当前字符的最远边界
            right = max(right, hash[s[i] - 'a']);
            if (i == right) {
                // 更新答案数组
                result.push_back(right - left + 1);
                // 更新左边界
                left = i + 1;
            }
        }
        return result;
    }
    // 法二用unordered_map
    vector<int> partitionLabels(string s) {
        vector<int> result;
        result.clear();
        if (s.size() == 0) {
            return result;
        }
        unordered_map<char, int> hash_map; // 记录每个字符的最远出现位置
        for (int i = 0; i < s.size(); i++) {
            hash_map[s[i]] = i;
        }
        // 定义滑动窗口位置
        // 就是通过滑动窗口来分辨出分割的区间
        for (int i = 0, left = 0, right = 0; i < s.size(); i++) {
            // 找到当前字符的最远边界
            right = max(right, hash_map[s[i] - 'a']);
            if (i == right) {
                // 更新答案数组
                result.push_back(right - left + 1);
                // 更新左边界
                left = i + 1;
            }
        }
        return result;
    }
};