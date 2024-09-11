/*
 * @Author: Jean_Leung
 * @Date: 2024-09-11 12:34:10
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-11 13:38:52
 * @FilePath: \code\slow_fast_leetcode844.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

#define MAX_ 1e4
#define MIN_ -1e4

class Solution {
  public:
    bool backspaceCompare(string s, string t) {
        get(s);
        get(t);
        return s == t;
    }
    void get(string &s) {
        int slow_index = 0;
        for (int fast_index = 0; fast_index < s.size(); fast_index++) {
            if (s[fast_index] != '#') {
                s[slow_index++] = s[fast_index];
            } else if (slow_index != 0) {
                // slow_index --是这里的关键
                slow_index--;
            }
        }
        s.resize(slow_index);
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    // vector<int> test_nums{0, 1, 2, 3, 3, 0, 4, 2};
    string s = "a#c";
    string t = "b";
    bool ans = solution.backspaceCompare(s, t);
    std::cout << "ans:" << ans << std::endl;
    return 0;
}