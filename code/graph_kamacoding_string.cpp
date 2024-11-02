/*
 * @Author: Jean_Leung
 * @Date: 2024-10-30 20:15:48
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-10-31 17:02:01
 * @FilePath: \code\graph_kamacoding_string.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
int main() {
    // 需要根据输入的字符串进行无向图构造
    // 如果和当前字符串只差一个字符
    // 那么就需要将当前字符串与只差一个字符的字符串相连
    // 起始字符串，结尾字符串，字符串组
    string begin_str, end_str, str;
    int n;
    // 用unordered_set来储存，达到去重的效果
    unordered_set<string> str_set;
    cin >> n;
    cin >> begin_str >> end_str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        str_set.insert(str);
    }
    // {记录的字符串,路径长度}
    // 记录strSet里的字符串是否被访问过，同时记录路径长度
    unordered_map<string, int> visited_map;
    // 这道题适合用BFS来做，因为无向图的最短路径适合用BFS
    // BFS是一圈一圈的进行搜索，肯定是最短路径
    queue<string> que;
    que.push(begin_str);
    // 加入vistited里面,表示访问过
    visited_map.insert(pair<string, int>(begin_str, 1));
    while (!que.empty()) {
        string word = que.front();
        que.pop();
        int path = visited_map[word];
        // 要在这个字符连接的字符开始寻找
        // 开始在这个str中，挨个字符去替换
        for (int i = 0; i < word.size(); i++) {
            // 用一个新字母去替代字母
            string new_word = word;
            for (int j = 0; j < 26; j++) {
                new_word[i] = j + 'a';
                if (new_word == end_str) {
                    cout << path + 1 << endl;
                    return 0;
                }
                // 字符串集合里出现new_word,且new_word没有访问过
                if (str_set.find(new_word) != str_set.end() &&
                    visited_map.find(new_word) == visited_map.end()) {
                    // 添加访问信息
                    visited_map.insert(pair<string, int>(new_word, path + 1));
                    que.push(new_word);
                }
            }
        }
    }
    cout << 0 << endl;
}

// 但是我认为可能更优解是利用这些字符串先构造无向图
