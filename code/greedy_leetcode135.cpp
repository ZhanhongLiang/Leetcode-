/*
 * @Author: Jean_Leung
 * @Date: 2024-10-17 11:34:27
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-17 12:24:53
 * @FilePath: \code\greedy_leetcode135.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
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

/**
 *贪⼼算法⼀般分为如下四步：
    将问题分解为若⼲个⼦问题
    找出适合的贪⼼策略
    求解每⼀个⼦问题的最优解
    将局部最优解堆叠成全局最优解
        这个四步其实过于理论化了，我们平时在做贪⼼类的题⽬
        很难去按照这四步去思考，真是有点“鸡肋”。 做题的时候，只要想清楚 局部最优
        是什么，如果推导出全局最优，其实就够了。
 */

class Solution {
  public:
    int candy(vector<int> &ratings) {
        // 需要两次贪心
        //     1. 从左到右遍历确定当前分发糖果数
        //            局部最优:只有右边评分比左边大,右边孩子多一个糖果
        //            全局最优:相邻的孩子,评分高的右孩子获得比左边孩子更多的糖果
        //     2.从右到左遍历,保证第i个小孩的糖果数量即大于左边的也大于右边的
        //                   如果ratings[i-1] > ratings[i]
        //               每次在candy_vec[i-1]  和
        //               candy_vec[i]+1中取最大值,candy_vec[i-1] =
        //               candy_vec[i]+1
        //              因为前面第一步只能保证右边一定比左边多,但是不能保证左边的比右边的大
        // int candy_vec[ratings.size(), 1]; // 记录分发糖果数
        vector<int> candy_vec(ratings.size(), 1);
        // 先从左往右遍历
        for (int i = 1; i < ratings.size(); i++) {
            // 如果当rating[i] > ratings[i-1]的时候
            if (ratings[i] > ratings[i - 1]) {
                candy_vec[i] = candy_vec[i - 1] + 1;
            }
        }
        // 从右往左遍历
        for (int i = ratings.size() - 2; i >= 0; i--) {
            // 如果左边比右边大,那么取最大值
            if (ratings[i] > ratings[i + 1]) {
                candy_vec[i] = max(candy_vec[i], candy_vec[i + 1] + 1);
            }
        }
        // 统计糖果总数
        int result = 0;
        for (int i = 0; i < ratings.size(); i++) {
            result += candy_vec[i];
        }
        return result;
    }
};