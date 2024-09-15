/*
 * @Author: Jean_Leung
 * @Date: 2024-09-12 13:49:45
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-14 12:01:19
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
        // 因为是找最小字串，从反证法来看，是满足右指针递增，左指针也是递增的情况
        // 所以我们可以用 滑动窗口法
        unordered_map<char, int> win_hash,
            t_hash; // 建立维护两个哈希表，key为字符，value为int类型
        string result; // 答案字符串
        for (auto x : t) {
            t_hash[x]++;
        }
        // 遍历s串
        for (int left = 0, right = 0, count = 0; right < s.size(); right++) {
            win_hash[s[right]]++;
            // count 是记录窗口内字符数量
            // 什么时候count可以++呢,当win_hash[s[right]] <
            // t_hash[s[right]]的时候
            if (win_hash[s[right]] <= t_hash[s[right]]) {
                count++;
            }
            // 需要进行试探
            // 当左指针的字符数量在窗口内大于该字符出现在t内的时候
            // 需要左指针递增进行试探
            while (win_hash[s[left]] > t_hash[s[left]]) {
                win_hash[s[left++]]--;
            }
            // 更新结果值
            if (count == t.size()) {
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