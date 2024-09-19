/*
 * @Author: Jean_Leung
 * @Date: 2024-09-19 14:18:21
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-19 14:24:49
 * @FilePath: \code\hash_table_leetcode383.cpp
 * @Description: 赎金信
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

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
    bool canConstruct(string ransomNote, string magazine) {
        // 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由
        // magazine 里面的字符构成
        // magazine 中的每个字符只能在 ransomNote 中使用一次
        // 使用map映射来解决该类问题,key代表magazie中字符,value代表magazie出现的次数
        unordered_map<char, int> magazine_map;
        for (auto x : magazine) {
            magazine_map[x]++;
        }
        for (auto x : ransomNote) {
            if (--magazine_map[x] == -1) {
                return false;
            }
        }
        return true;
    }
};