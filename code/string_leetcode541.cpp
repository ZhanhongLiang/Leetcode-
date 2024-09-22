/*
 * @Author: Jean_Leung
 * @Date: 2024-09-20 14:07:23
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-22 12:02:23
 * @FilePath: \code\string_leetcode541.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

class Solution {
  public:
    // void reverseString(string &s, int k) {
    //     // 如果m
    //     // 原地算法
    //     // 必须原地对s进行反转
    //     // 可以用双指针法
    //     if (s.size() >= k && s.size() < 2 * k) {
    //         for (int i = 0, j = k - 1; i < k / 2; i++, j--) {
    //             swap(s[i], s[j]);
    //         }
    //     } else {
    //         for (int i = 0, j = s.size() / 2 - 1; i < (s.size() / 4);
    //              i++, j--) {
    //             swap(s[i], s[j]);
    //         }
    //     }
    // }
    string reverseStr(string s, int k) {
        // 分类讨论
        for (int i = 0; i < s.size(); i += 2 * k) {
            int j = i; // 窗口左端点
            int m = min(i + k, (int)s.size());
            // 左闭右开
            reverse(s.begin() + j, s.begin() + m);
        }
        return s;
    }
};

int main() {
    Solution solution;
    string test = "abcd";
    string ans;
    ans = solution.reverseStr(test, 4);
    std::cout << "ans :" << ans;
}