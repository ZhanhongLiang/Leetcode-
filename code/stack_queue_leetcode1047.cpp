/*
 * @Author: Jean_Leung
 * @Date: 2024-09-24 13:08:15
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-24 13:47:39
 * @FilePath: \code\stack_queue_leetcode1047.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

// 栈操作经典题目
class Solution {
  public:
    string removeDuplicates(string s) {
        // 原地算法, 设置答案字符串
        if (s.empty()) {
            return s;
        }
        stack<char> s_stack; // 字符栈
        s_stack.push(s[0]);  // 压入栈
        for (int i = 1; i < s.size(); i++) {
            if (!s_stack.empty()) {
                char temp = s_stack.top(); // 栈顶元素
                if (temp == s[i]) {
                    // 拿当前元素
                    s_stack.pop();
                } else {
                    s_stack.push(s[i]);
                }
            } else {
                s_stack.push(s[i]);
            }
        }
        // 用原来数组
        s.erase(s.begin(), s.end());
        // 将栈元素放进s中
        while (!s_stack.empty()) {
            int temp = s_stack.top();
            s += temp;
            s_stack.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    string test = "abbaca";
    Solution solution;
    string ans = solution.removeDuplicates(test);
    std::cout << "ans :" << ans;
}