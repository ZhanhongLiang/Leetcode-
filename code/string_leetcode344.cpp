/*
 * @Author: Jean_Leung
 * @Date: 2024-09-20 14:00:33
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-20 14:07:31
 * @FilePath: \code\string_leetcode344.cpp
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
    void reverseString(vector<char> &s) {
        // 原地算法
        // 必须原地对s进行反转
        // 可以用双指针法
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
};