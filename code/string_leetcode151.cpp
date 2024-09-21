/*
 * @Author: Jean_Leung
 * @Date: 2024-09-21 12:34:24
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-21 16:23:36
 * @FilePath: \code\string_leetcode151.cpp
 * @Description: 反转字符串中的单词
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
    /**
     * @description:
     * @param {string} s
     * @return {*}
     */
    string reverseWords(string s) {
        /**
         * - 先反转每个单词，然后再反转整个句子,最后达到效果
           最为关键是如何在O(1)的空间复杂度里面进行操作
           i和j是设置第二个滑动窗口，k和t是设置第一个滑动窗口
             -
         `关键是要设置两个滑动窗口,第一个是从数组的头部开始走,用来存第二个滑动窗口的单词`,怎么设置,用k和t来指定第一个滑动窗口的位置
                - `因为这样可以防止句子的最前面的空格占位`
               设置遍历工作指针i,
         i作为滑动窗口的左指针,j作为滑动窗口的右指针,这个就是第二个滑动窗口
                   用来进行遍历下一个单词用的
         */
        // 第一个滑动窗口的开头处,用来放置第二个滑动窗口扫描的单词
        int k = 0;
        // 第二个滑动窗口的开头处
        for (int i = 0; i < s.size(); i++) {
            // 先查找第二个遍历窗口位置
            // 如果当前工作指针i位置为空格,则继续遍历找到不是空格的位置
            // i是第二个窗口的右指针
            if (s[i] == ' ') {
                continue;
            }
            // 这时候s[i] != ' '那么就可以利用j来寻找第一个单词末尾位置
            // 且这个时候需要设定第一个窗口的右指针
            // 令t = k, 就是设定好第一个窗口的初始位置
            int j = i, t = k;
            while (j < s.size() && s[j] != ' ') {
                // 这个时候就是将第二个窗口的单词复制到第一个窗口中
                s[t++] = s[j++];
            }
            // 这个时候需要反转第一个窗口中复制好的单词
            reverse(s.begin() + k, s.begin() + t);
            // 因为一个窗口中的单词已经反转好了
            // 需要在后面添加空格
            s[t++] = ' ';
            // 添加完空格后，需要继续下一步循环操作
            // 这个时候i位置应该指向j,因为j这个时候的位置不是空格，是下一个单词的开头位置
            // 且k位置也需要更新到t位置,因为第二窗口位置需要往右挪
            i = j;
            k = t;
        }
        // 当i遍历完后,i必定是在最后的位置
        // 这个时候如果句子多出的很多空格的话,s的长度必定不对,需要删除最后句子中冗余部分
        // 怎么删除呢?因为第一个窗口右指针左边所有的句子都是我们想要的
        // 且这个时候k = t,刚好我们最后位置必定是空格,因为s[t++] = ' '
        // 这个是多出来的空格也是需要删除的
        // 所以需要k往左移
        if (k) {
            k--;
        }
        // 这个时候k的位置就是需要的句子末尾
        // 这个时候删除末尾就行
        s.erase(s.begin() + k, s.end());
        // 最后进行反转
        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    Solution solution;
    string test = "  hello world  ";
    string ans = solution.reverseWords(test);
    std::cout << "ans :" << ans;
}