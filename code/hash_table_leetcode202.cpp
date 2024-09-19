/*
 * @Author: Jean_Leung
 * @Date: 2024-09-19 13:11:59
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-19 13:27:03
 * @FilePath: \code\hash_table_leetcode202.cpp
 * @Description: 判断一个数是否是快乐数
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

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
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        // 设置unordered_set,这个是无序的set，不能重复
        unordered_set<int> sum_set;
        while (1) {
            int sum = getSum(n);
            if (sum == 1) {
                return true;
            }
            if (sum_set.find(sum) != sum_set.end()) {
                return false;
            } else {
                sum_set.insert(sum);
            }
            n = sum;
        }
    }
};
