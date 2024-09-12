/*
 * @Author: Jean_Leung
 * @Date: 2024-09-11 12:34:10
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-12 11:39:15
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
        // 比较两个字符串，利用快慢指针法，因为相对位置不能改变
        // 快慢指针都得在同一侧
        int slow_index = 0; // 慢指针
        for (int fast_index = 0; fast_index < s.size(); fast_index++) {
            if (s[fast_index] != '#') {
                s[slow_index++] = s[fast_index];
            } else if (slow_index != 0) {
                // 这里设置判断!=0是因为防止slow_index 小于0
                // 需要回退一格，因为不相等
                // 相当于删掉前面一个字母
                slow_index--;
            }
        }
        s.resize(slow_index); // 重新设置字符串大小
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