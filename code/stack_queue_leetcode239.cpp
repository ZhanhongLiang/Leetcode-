/*
 * @Author: Jean_Leung
 * @Date: 2024-09-24 18:38:53
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-24 19:57:30
 * @FilePath: \code\stack_queue_leetcode239.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

class Solution {
  private:
    // 需要设计单调队列来维护窗口中最大值
    class MyQueue {
      public:
        // 要用双端队列,
        deque<int> q;
        //
        void pop(int value) {
            if (value == q.front() && !q.empty()) {
                q.pop_front();
            }
        }
        //
        void push(int value) {
            while (value > q.back() && !q.empty()) {
                q.pop_back();
            }
            q.push_back(value);
        }

        int front() { return q.front(); }
    };

  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // 将k个数放进que中
        vector<int> ans;
        MyQueue que;
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        // 然后返回当前的最大值
        ans.push_back(que.front());
        for (int i = k; i < nums.size(); i++) {
            // 压出栈
            que.pop(nums[i - k]);
            que.push(nums[i]);
            ans.push_back(que.front());
        }
        return ans;
    }
};

int main() {
    vector<int> test{1, 3, -1, -3, 5, 3, 6, 7};
    Solution solution;
    vector<int> ans = solution.maxSlidingWindow(test, 3);
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << "\n";
    }
    std::cout << std::endl;
}