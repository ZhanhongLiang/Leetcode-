/*
 * @Author: Jean_Leung
 * @Date: 2024-10-12 10:22:31
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-12 12:52:22
 * @FilePath: \code\backtracking_leetcode93.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
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
 * void backtracking(参数) {
        if (终⽌条件) {
            存放结果;
            return;
        }
        for (选择：本层集合中元素（树中节点孩⼦的数量就是集合的⼤⼩）) {
            处理节点;
            backtracking(路径，选择列表); // 递归
            回溯，撤销处理结果
        }
    }
 */

class Solution {
  public:
    vector<string> res; // 结果集合
    string path;        // 工作遍历集合
    vector<string> restoreIpAddresses(string s) {
        // 需要在这个字符串中找到合适的IP地址组合,返回有效的IP地址
        if (s.empty()) {
            return res;
        }
        // result.clear();
        if (s.size() < 4 || s.size() > 12)
            return res; // 算是剪枝了
        // string path;
        dfs(s, 0, 0);
        return res;
    }
    /**
     * @description: 校验现在字符串是否合法
     * @param {string} str
     * @return {*}
     */
    bool isValid(const string &str, int start, int end) {
        if (start > end) {
            return false;
        }
        if (start != end && str[start] == '0') {
            return false;
        }
        // int digits = std::stoi(str);
        // if (digits > 255 || digits < 0) {
        //     return false;
        // }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (str[i] > '9' || str[i] < '0') {
                return false;
            }
            num = num * 10 + (str[i] - '0');
            if (num > 255) {
                return false;
            }
        }
        return true;
    }
    // 还是属于切割穷举问题
    /**
     * @description: 穷举回溯算法
     * @param {string} s
     * @param {int} start_index
     * @param {string} path
     * @return {*}
     */
    void dfs(string &s, int start_index, int point_num) {
        // 终止条件
        // 终止条件是出现三个逗号就结束
        if (point_num == 3) {
            // 判断第四段子字符串是否合法
            if (isValid(s, start_index, s.size() - 1)) {
                res.push_back(s);
            }
            return;
        }

        // 节点遍历
        for (int i = start_index; i < s.size(); i++) {
            // 将当前的截取出来
            // string temp = s.substr(start_index, i - start_index + 1);
            if (isValid(s, start_index, i)) {
                // 如果符合,则将其分割出来
                s.insert(s.begin() + i + 1, '.');
                point_num++;
                dfs(s, i + 2, point_num);
                point_num--;
                s.erase(s.begin() + i + 1);
            } else {
                break;
            }
            // string temp = s.substr(start_index, i - start_index + 1);
            // if (isValidII(temp)) {
            //     temp += '.';
            //     path.append(temp);
            //     point_num++;
            // } else {
            //     continue;
            // }
            // dfs(s, i + 1, point_num);
            // point_num--;
            // path.erase(start_index, i - start_index + 1);
        }
    }

    bool isValidII(const string &str) {
        if (str.size() > 1 && str[0] == '0') {
            return false;
        }
        // int digits = std::stoi(str);
        // if (digits > 255 || digits < 0) {
        //     return false;
        // }
        int num = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] > '9' || str[i] < '0') {
                return false;
            }
            num = num * 10 + (str[i] - '0');
            if (num > 255) {
                return false;
            }
        }
        return true;
    }

    // Y神写法,不好理解但是可以尝试理解
    /**
     * @description: u代表层搜索开始的位置,相当于start_index
     *                  k代表当前层已经搜到第几个数??
     *                  path代表遍历路径
     * @param {string &} s
     * @param {int} u
     * @param {int} k
     * @param {string} path
     * @return {*}
     */
    void dfsII(string &s, int u, int k, string path) {
        // 终止条件
        if (u == s.size()) {
            // 这里代表字符串已经分割出四个数了
            // 满足条件
            if (k == 4) {
                // 这里进行删除最后一个.
                // 因为会多出一个点
                path.pop_back();
                res.push_back(path);
            }
            return;
        }
        // 代表当前已经搜索到超出4个数,代表肯定是不能
        // 为什么是4个数呢??
        // 因为12个字符,有三个.必然存在四个分割的数
        // 所以这可以作为判断条件
        if (k == 4) {
            return;
        }

        for (int i = u, t = 0; i < s.size(); i++) {
            // 有前置零的情况
            if (i > u && s[u] == '0') {
                break;
            }
            t = t * 10 + (s[i] - '0'); // 将当前的数转换为数字
            if (t <= 255) {
                // 为什么不需要path进行回溯，因为path作为传入参数
                // 利用了递归的特性,自动会回到上一层的状态
                // 同理i和k也是这样
                // 这就是不使用全局变量的好处
                dfsII(s, i + 1, k + 1, path + to_string(t) + '.');
            } else {
                break;
            }
        }
    }
};

int main() {
    string test = "25525511135";
    Solution solution;
    vector<string> ans = solution.restoreIpAddresses(test);
    for (auto x : ans) {
        std::cout << x << "," << std::endl;
    }
    return 0;
}