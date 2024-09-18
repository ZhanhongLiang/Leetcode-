/*
 * @Author: Jean_Leung
 * @Date: 2024-09-18 13:54:00
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-18 14:26:18
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
        if (s.size() != t.size()) {
            return false;
        }
        // 设置两个unordered_map来分别统计s中的词数量和t中词数量
        unordered_map<char, int> s_hash;
        for (auto x : s) {
            s_hash[x]++;
        }
        // for (auto x : t) {
        //     t_hash[x]++;
        // }
        // 判断各自容器中的容器的数量是否相等
        // 需要设置迭代器进行迭代
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
