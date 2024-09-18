/*
 * @Author: Jean_Leung
 * @Date: 2024-09-17 22:24:50
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-17 23:01:09
 * @FilePath: \code\link_list_leetcode160.cpp
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 需要设置虚拟结点
        // ListNode *dummy_head_A = new ListNode();
        // ListNode *dummy_head_B = new ListNode();
        // dummy_head_A->next = headA;
        // dummy_head_B->next = headB;
        // 先求出各个链表的长度
        int size_A = 0, size_B = 0;
        ListNode *p = headA;
        ListNode *q = headB;
        while (p->next) {
            size_A++;
            p = p->next;
        }
        while (q->next) {
            size_B++;
            q = q->next;
        }
        ListNode *fast = new ListNode(); // 快指针
        ListNode *slow = new ListNode(); // 慢指针
        int move_step = 0; // 需要让工作指针先移动的步数
        if (size_A > size_B) {
            move_step = size_A - size_B;
            fast = headA;
            slow = headB;
        } else {
            move_step = size_B - size_A;
            fast = headB;
            slow = headA;
        }
        while (move_step--) {
            fast = fast->next; // 先让快指针走
        }
        // 快慢同时走
        while (fast) {
            if (slow == fast) {
                return fast;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return NULL;
    }
};
