/*
 * @Author: Jean_Leung
 * @Date: 2024-09-22 15:08:23
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-22 16:02:53
 * @FilePath: \code\string_leetcode459.cpp
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
    bool repeatedSubstringPattern(string s) {
        // 这道题目太难了??
        // 涉及到串的弱周期理论和周期理论,KMP算法
        // 需要严格的数学证明,我先放着,等几天学完再来看这道题
        // 给定一个字符串，判断是否可以由某个字串重复构成
    }
    // 简单实现，但是没有数学证明
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        t.erase(t.begin());
        t.erase(t.end() - 1); // 掐头去尾
        if (t.find(s) != std::string::npos) {
            return true; // r
        }
        return false;
    }
};