# 203 [移除链表元素](https://leetcode.cn/problems/remove-linked-list-elements/description/)

## 题目

>给你一个链表的头节点 `head` 和一个整数 `val` ，请你删除链表中所有满足 `Node.val == val` 的节点，并返回 **新的头节点** 。

示例1:

![img](https://assets.leetcode.com/uploads/2021/03/06/removelinked-list.jpg)

```
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]
```

**示例 2：**

```
输入：head = [], val = 1
输出：[]
```

**示例 3：**

```
输入：head = [7,7,7,7], val = 7
输出：[]
```

 

**提示：**

- 列表中的节点数目在范围 `[0, 104]` 内
- `1 <= Node.val <= 50`
- `0 <= val <= 50`



## 题目大意

## 解题思路

## 代码

```c++
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

```



