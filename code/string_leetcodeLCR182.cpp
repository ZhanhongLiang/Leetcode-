/*
 * @Author: Jean_Leung
 * @Date: 2024-09-22 12:03:02
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-22 12:21:52
 * @FilePath: \code\string_leetcodeLCR182.cpp
 * @Description:
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
    // 非原地算法
    string dynamicPassword(string password, int target) {
        // 移动前k个字符到最后位置,没想到原地算法怎么操作
        // 如果非原地算法
        string temp = password.substr(0, target);
        password.erase(password.begin(), password.begin() + target);
        // 然后将temp移动到password上
        password.append(temp);
        return password;
    }
    // 原地算法怎么做?
    string dynamicPasswordII(string password, int target) {
        // 可以先将整个字符串反转
        // 然后再进行分别两个自己旋转
        // 设置两个区间,左闭右开
        // [password.begin(),password.begin()+password.size()-target]
        // [password.begin()+password.size()-target,password.end()];
        // 分别对这两个进行反转,这样就达到原地操作了
        reverse(password.begin(), password.end());
        reverse(password.begin(), password.begin() + password.size() - target);
        reverse(password.begin() + password.size() - target, password.end());
        return password;
    }
};
