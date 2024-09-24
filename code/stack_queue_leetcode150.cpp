/*
 * @Author: Jean_Leung
 * @Date: 2024-09-24 14:00:02
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-24 14:48:25
 * @FilePath: \code\stack_queue_leetcode150.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
        // 设置数字栈
        stack<long long> ans;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
                tokens[i] == "/") {
                long long num1 = ans.top();
                ans.pop();
                long long num2 = ans.top();
                ans.pop();
                if (tokens[i] == "+") {
                    ans.push(num2 + num1);
                }
                if (tokens[i] == "-") {
                    ans.push(num2 - num1);
                }
                if (tokens[i] == "*") {
                    ans.push(num2 * num1);
                }
                if (tokens[i] == "/") {
                    ans.push(num2 / num1);
                }
            } else {
                long long temp = stoll(tokens[i]);
                ans.push(temp);
            }
        }
        return ans.top();
    }
};

int main() {
    vector<string> test({"2", "1", "+", "3", "*"});
    Solution solution;
    int ans = solution.evalRPN(test);
    std::cout << "ans :" << ans;
}