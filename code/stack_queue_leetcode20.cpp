/*
 * @Author: Jean_Leung
 * @Date: 2024-09-23 11:46:51
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-24 13:06:50
 * @FilePath: \code\stack_queue_leetcode20.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;
// 判断有效的括号字符串
class Solution {
  public:
    bool isValid(string s) {
        // 经典题目，很简单
        // 用一个栈就行
        stack<char> s_stack; // 代表括号栈
        int size = s.size();
        // 如果是奇数,肯定不合法,如果是偶数继续用栈判断
        // 字符串为空也返回false
        if (size % 2 || s.empty()) {
            return false;
        }
        for (int i = 0; i < size; i++) {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
                s_stack.push(s[i]);
            } else {
                // 遇到右括号了,那么就进行pop操作
                if (s_stack.size() && s[i] == '}') {
                    // 找到离他最近的'}'括号
                    // 如果中间存在其他括号，那就是非法
                    int temp = s_stack.top();
                    if (temp == '{') {
                        s_stack.pop();
                    } else {
                        return false;
                    }
                } else if (s_stack.size() && s[i] == ']') {
                    int temp = s_stack.top();
                    if (temp == '[') {
                        s_stack.pop();
                    } else {
                        return false;
                    }
                } else if (s_stack.size() && s[i] == ')') {
                    int temp = s_stack.top();
                    if (temp == '(') {
                        s_stack.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        return s_stack.empty();
    }
};

int main() {
    string test = "{}[(]";
    Solution solution;
    bool ans = solution.isValid(test);
    std::cout << "ans : " << ans;
}

