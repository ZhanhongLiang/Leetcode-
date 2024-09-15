/*
 * @Author: Jean_Leung
 * @Date: 2024-09-15 17:52:39
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-15 18:23:40
 * @FilePath: \code\list_link_leetcode203.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    /* data */
};

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <vector>

#define random(x) (rand() % x)
using namespace std;

class Solution {
  public:
    ListNode *removeElements(ListNode *head, int val) {
        // 虚拟头节点法
        ListNode *dummy = new ListNode(-1); // 设立虚拟头节点
        dummy->next = head;                 // 虚拟头结点指向head
        ListNode * p = dummy;
        // 判断当前结点是否为空
        while (p) {
            // 判断当前结点的值是否为为val
            ListNode *q = p->next; // 设立临时结点，防止断链
            // 当q的值是val,且q存在,则一直遍历
            while (q && q->val == val) {
                q = q->next;
            }
            p->next = q;
            p = p->next;
        }
        return dummy->next;
    }
};
