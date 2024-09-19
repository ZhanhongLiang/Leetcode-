/*
 * @Author: Jean_Leung
 * @Date: 2024-09-18 13:54:00
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-19 12:14:45
 * @FilePath: \code\hash_table_leetcode242.cpp
 * @Description:哈希表刷题,leetcode242 判断t是否是s的字母异位词
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

class Sloution {
  public:
    bool isAnagram(string s, string t) {
        // 判断t是否是s的异位字母词
        if (t.size() != s.size()) {
            return false;
        }
        unordered_map<char, int> s_hash;
        for (auto x : s) {
            s_hash[x]++;
        }
        // 进行匹配
        for (auto x : t) {
            if (--s_hash[x] == -1) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Sloution sloution;
    string s = "abc";
    string t = "bac";
    bool ans = sloution.isAnagram(s, t);
    std::cout << "ans : " << ans << std::endl;
}
