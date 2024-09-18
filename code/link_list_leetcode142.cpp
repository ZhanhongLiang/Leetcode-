/*
 * @Author: Jean_Leung
 * @Date: 2024-09-17 22:30:05
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-18 13:20:26
 * @FilePath: \code\link_list_leetcode142.cpp
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
     * @description: 找到环形链表第一个入口
     * @param {ListNode} *head
     * @return {*}
     */
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head; // 快指针
        ListNode *slow = head; // 慢指针
        // 快指针比慢指针每次走多一步
        while (fast && fast->next) {
            // 慢指针需要走一步
            slow = slow->next;
            // 快指针需要走两步
            fast = fast->next->next;
            if (fast == slow) {
                // 当相遇的时候，那么只要将相遇位置重新走
                // index1为相遇结点，index2为头结点
                // 同时走一步，当相遇时候，相遇的位置就是入口结点
                ListNode *index1 = fast;
                ListNode *index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;
            }
        }
        return NULL;
    }
};