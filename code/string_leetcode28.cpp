/*
 * @Author: Jean_Leung
 * @Date: 2024-09-22 12:42:03
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-22 15:04:28
 * @FilePath: \code\string_leetcode28.cpp
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
    // 需要构建最长公共前后缀表，也就是所谓的netx数组
    // 根据代码随想录的解释,
    // 前缀是除了"最后一个字符"中的连续字串
    // 后缀是除了"第一个字符"中的连续字串
    // 模式串中的最长公共前后缀表是每个字符位置(包括当前字符--所谓连续串)之前的最长公共前后缀<长度>
    // 例如"aabaaf","a"是下标0位置的连续串,其最长公共前后缀长度是0
    // "aa"是下标1位置的连续串，其最长公共前后缀是长度是1
    // "aab"是下标2位置的连续串，其最长公共前后缀是长度是0
    // "aaba"是下标3位置的连续串,其最长公共前后缀是长度是1
    // "aabaa"是下标4位置的连续串,其最长公共前后缀是长度是2
    // "aabaaf"是下标5位置的连续串,其最长公共前后缀是长度是0
    // 总结对应的next数组(最长公共前后缀长度表)就是[0,1,0,1,2,0]
    // 好我们来构建next数组

    // 先构建第一个版本,将next数组整体的数字算数右移一位
    // 也就是[-1,0,-1,0,1,-1]
    void getNext(int *next, const string &s) {
        // 定义两个指针i和j，j指向前缀末尾位置，i指向后缀末尾位置
        int j = -1;
        // next[i] 表示 i（包括i）之前最⻓相等的前后缀⻓度（其实就是j）
        next[0] = j;
        for (int i = 1; i < s.size(); i++) {     // 注意i从1开始
            while (j >= 0 && s[i] != s[j + 1]) { // 前后缀不相同了
                j = next[j];                     // 向前回退
            }
            if (s[i] == s[j + 1]) { // 找到相同的前后缀
                j++;
            }
            next[i] = j; // 将j（前缀的⻓度）赋给next[i]
        }
    }
    // 先构建第二个版本,原版
    // 也就是[0,1,0,1,2,0]
    void getNextII(int *next, const string &s) {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            while (
                j > 0 &&
                s[i] !=
                    s[j]) { // j要保证⼤于0，因为下⾯有取j-1作为数组下标的操作
                j = next[j - 1]; // 注意这⾥，是要找前⼀位的对应的回退位置了
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        vector<int> next(needle.size());
        getNext(&next[0], needle);
        int j = -1; // // 因为next数组里记录的起始位置为-1
        for (int i = 0; i < haystack.size(); i++) { // 注意i就从0开始
            while (j >= 0 && haystack[i] != needle[j + 1]) { // 不匹配
                j = next[j]; // j 寻找之前匹配的位置
            }
            if (haystack[i] == needle[j + 1]) { // 匹配，j和i同时向后移动
                j++;                            // i的增加在for循环里
            }
            if (j == (needle.size() - 1)) { // 文本串s里出现了模式串t
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};
