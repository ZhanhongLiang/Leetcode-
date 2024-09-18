/*
 * @Author: Jean_Leung
 * @Date: 2024-09-17 21:59:52
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-17 22:14:42
 * @FilePath: \code\link_list_leetcode19.cpp
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy_head = new ListNode();
        dummy_head->next = head;
        // 固定窗口滑动法
        // 设置一个长度为n的窗口，在链表上面进行滑动
        //
        ListNode *p = dummy_head; // 快指针
        // 快指针先滑动n位置
        while (n-- && p) {
            p = p->next;
        }
        p = p->next;              // 要走n+1步，因为有虚拟头结点
        ListNode *q = dummy_head; // 慢指针
        // 当p移动到最后一个结点的时候，那么q距离p是n+1个位置
        while (p) {
            p = p->next; // 快指针移动
            q = q->next; // 慢指针移动
        }
        // ListNode *temp = q->next;
        q->next = q->next->next;
        // temp->next = nullptr; // 将该结点指向空
        // delete temp;          // 释放内存
        return dummy_head->next;
    }
};