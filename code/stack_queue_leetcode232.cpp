/*
 * @Author: Jean_Leung
 * @Date: 2024-09-23 10:41:07
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-23 10:53:56
 * @FilePath: \code\stack_queue_leetcode232.cpp
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
// 用栈实现队列
class MyQueue {
  public:
    MyQueue() {
        // 初始化栈
    }

    void push(int x) {
        // push到输入栈
        stIN.push(x);
    }

    int pop() {
        // 先将输入栈中所有的数据压入到输出栈中
        // 然后再将输出栈的数据弹出
        int ans = 0;
        if (stOut.empty()) {
            // 将输入栈输出到输出栈中
            // 需要遍历
            while (!stIN.empty()) {
                int temp = stIN.top();
                stIN.pop();
                stOut.push(temp);
            }
        }
        ans = stOut.top();
        stOut.pop();
        return ans;
    }
    // 返回队列中第一个元素
    int peek() {
        // 先将输入栈中所有的数据压入到输出栈中
        // 然后再将输出栈的数据弹出
        int ans = 0;
        if (stOut.empty()) {
            // 将输入栈输出到输出栈中
            // 需要遍历
            while (!stIN.empty()) {
                int temp = stIN.top();
                stIN.pop();
                stOut.push(temp);
            }
        }
        ans = stOut.top();
        return ans;
    }

    bool empty() {
        // 当输入栈和输出栈都是空的时候才能判定队列是空的
        if (stIN.empty() && stOut.empty()) {
            return true;
        }
        return false;
    }

  private:
    // 用栈来实现
    // 需要设置输出栈和输入栈
    // 因为这个是必须的，一个栈是实现不了队列的
    stack<int> stIN;
    stack<int> stOut;
};