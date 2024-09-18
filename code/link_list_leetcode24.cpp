/*
 * @Author: Jean_Leung
 * @Date: 2024-09-17 21:33:51
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-17 21:58:53
 * @FilePath: \code\link_list_leetcode24.cpp
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
    /**
     * @description: 两两交换其相邻的结点
     * @param {ListNode} *head
     * @return {*}
     */
    ListNode *swapPairs(ListNode *head) {
        // 采用正常迭代的思想
        ListNode *dummy_head = new ListNode(0); // 虚拟头结点
        dummy_head->next = head;
        ListNode *p = dummy_head; // 工作遍历结点

        while (p->next && p->next->next) {
            ListNode *q = p->next;
            ListNode *temp = p->next->next->next; // 记录临时结点
            p->next = p->next->next;              // 重新链接,步骤一
            p->next->next = q;                    // 重新链接，步骤二
            p->next->next->next = temp;           // 重新连接，步骤三
            p = p->next->next;
        }
        return dummy_head->next;
    }
};