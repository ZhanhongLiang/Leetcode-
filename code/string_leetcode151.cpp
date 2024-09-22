/*
 * @Author: Jean_Leung
 * @Date: 2024-09-21 12:34:24
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-22 11:53:40
 * @FilePath: \code\string_leetcode151.cpp
 * @Description: 反转字符串中的单词
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
    /**
     * @description:
     * @param {string} s
     * @return {*}
     */
    string reverseWords(string s) {
        // 先设置第一个窗口的左指针
        int k = 0;
        for (int i = 0; i < s.size(); i++) {
            // 第二个窗口的左指针
            if (s[i] == ' ') {
                continue;
            }
            // 设定第一个窗口的右指针，第二个窗口的右指针
            int j = i, t = k;
            // 首先第二个窗口进行遍历查找
            while (j < s.size() && s[j] != ' ') {
                // 将第二个窗口的值赋值给第一个窗口,进行替代
                s[t++] = s[j++];
            }
            // 最后反转第一个窗口的的当前遍历单词
            reverse(s.begin() + k, s.begin() + t);
            // 然后最后在第一个窗口末尾填空格
            s[t++] = ' ';
            // 继续遍历下一个单词
            // 当前j位置就是空格位置,赋给i重新开始
            // 同理t也是
            i = j;
            k = t;
        }
        // 最后的单词位置必然是空格,因为s[t++] = ' ';
        // 所以得回退
        if (k) {
            k--;
        }
        // 且最后需要删除k之后的所有东西，因为多出空格冗余了
        s.erase(s.begin() + k, s.end());
        // 最后反转整个字符串
        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    Solution solution;
    string test = "  hello world  ";
    string ans = solution.reverseWords(test);
    std::cout << "ans :" << ans;
}