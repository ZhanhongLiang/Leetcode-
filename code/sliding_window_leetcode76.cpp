/*
 * @Author: Jean_Leung
 * @Date: 2024-09-12 13:49:45
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-12 15:10:56
 * @FilePath: \code\sliding_window_leetcode76.cpp
 * @Description:
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

class Solution {
  public:
    string minWindow(string s, string t) {
        // 因为是两个数组进行匹配
        // 我们需要维护一个map进行记录t字符串中每个字符出现的次数
        // 维护一个滑动窗口map记录窗口内每个字符出现的次数
        unordered_map<char, int> win_char_count, t_char_count;
        // 需要先统计t出现字符的次数
        for (auto x : t) {
            t_char_count[x]++;
        }
        string result; // 结果字符串
        // 滑动窗口思路,因为这题中left 和
        // right，明显窗口中left是随着right增加具有单调性的
        // count 记录当前窗口的字符出现次数
        for (int right = 0, left = 0, count = 0; right < s.size(); right++) {
            // 记录窗口中出现字符数量
            win_char_count[s[right]]++;
            // 记录窗口的统计字符数
            // 当窗口的当前字符出现的次数 <= t字符中当前字符出现的次数
            // 需要count++
            if (win_char_count[s[right]] <= t_char_count[s[right]]) {
                count++;
            }
            // 这一步最重要,当窗口中左指针的出现字符数>t中左指针出现字符数
            // 那么需要进行left++,且需要进行窗口值减少
            while (win_char_count[s[left]] > t_char_count[s[left]]) {
                win_char_count[s[left++]]--;
            }
            // 当count的值是等于t的长度，那么就需要更新result值
            if (count == t.size()) {
                // 最后一部就是记录当前窗口长度
                // 然后返回result值
                if (result.empty() || result.size() > right - left + 1) {
                    result = s.substr(left, right - left + 1);
                }
            }
        }
        return result;
    }
};
int main(int argc, char const *argv[]) {
    Solution solution;
    // vector<int> test_nums{0, 1, 2, 3, 3, 0, 4, 2};
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string ans = solution.minWindow(s, t);
    std::cout << "ans:" << ans << std::endl;
    return 0;
}