/*
 * @Author: Jean_Leung
 * @Date: 2024-10-18 15:40:47
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-18 16:11:12
 * @FilePath: \code\greedy_leetcode738.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
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
    int monotoneIncreasingDigits(int n) {
        // 先将n变成字符串
        string ans = to_string(n);
        // 然后从后往前开始遍历,假如遇到前面一位比后面一位大
        // 将前面一位--,当前一位不变,记录一次前面一位的下标i-1
        // 当前位为i，前面位置为i-1
        int index = 0;
        for (int i = ans.size() - 1; i > 0; i--) {
            if (ans[i] < ans[i - 1]) {
                // 将字符转换为int
                int num = ans[i - 1] - '0';
                num--;
                // 将int转换为字符
                ans[i - 1] = num + '0';
                // 记录暂时没变9的位数
                index = i;
            }
        }
        // 校验1234的特殊情况
        if (index == 0) {
            return n;
        }
        // 找到index位置，然后将index后面(包括index)全部置为9
        for (int i = index; i < ans.size(); i++) {
            int num = ans[i] - '0';
            num = 9;
            ans[i] = num + '0';
        }
        n = stoi(ans);
        return n;
    }
};