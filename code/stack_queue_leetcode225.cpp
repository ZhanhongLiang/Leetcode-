/*
 * @Author: Jean_Leung
 * @Date: 2024-09-23 11:14:14
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-23 11:31:37
 * @FilePath: \code\stack_queue_leetcode225.cpp
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
// 用队列来实现栈的FILO
class MyStack {
  public:
    MyStack() {}

    void push(int x) { q.push(x); }

    int pop() {
        // 需要将除了最后一个元素,其余元素都添加到队列的末尾
        int size = q.size();
        size--;
        while (size--) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        int ans = q.front();
        q.pop();
        return ans;
    }

    int top() {
        // 返回队列最后一个元素
        return q.back();
    }

    bool empty() {
        if (q.empty()) {
            return true;
        }
        return false;
    }

  private:
    // 输入队列和输出队列
    queue<int> q;
};