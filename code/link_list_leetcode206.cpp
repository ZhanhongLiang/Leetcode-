/*
 * @Author: Jean_Leung
 * @Date: 2024-09-16 18:17:41
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-16 18:43:59
 * @FilePath: \code\link_list_leetcode206.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        ListNode *dummy_head = new ListNode(); // 虚拟头节点
        // 头插构建表法
        ListNode *p = head; // 先保存头节点
        while (p) {
            ListNode *q = p->next; // 保存下个结点，防止断链
            p->next = dummy_head->next;
            dummy_head->next = p;
            p = q;
        }
        return dummy_head->next;
    }
};
