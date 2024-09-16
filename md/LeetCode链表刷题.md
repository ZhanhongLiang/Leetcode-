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

>删除链表中所有指定值的结点。

## 解题思路

>按照题意做即可

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



# 707 [设计链表](https://leetcode.cn/problems/design-linked-list/description/)

## 题目

>你可以选择使用单链表或者双链表，设计并实现自己的链表。
>
>单链表中的节点应该具备两个属性：`val` 和 `next` 。`val` 是当前节点的值，`next` 是指向下一个节点的指针/引用。
>
>如果是双向链表，则还需要属性 `prev` 以指示链表中的上一个节点。假设链表中的所有节点下标从 **0** 开始。
>
>实现 `MyLinkedList` 类：
>
>- `MyLinkedList()` 初始化 `MyLinkedList` 对象。
>- `int get(int index)` 获取链表中下标为 `index` 的节点的值。如果下标无效，则返回 `-1` 。
>- `void addAtHead(int val)` 将一个值为 `val` 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
>- `void addAtTail(int val)` 将一个值为 `val` 的节点追加到链表中作为链表的最后一个元素。
>- `void addAtIndex(int index, int val)` 将一个值为 `val` 的节点插入到链表中下标为 `index` 的节点之前。如果 `index` 等于链表的长度，那么该节点会被追加到链表的末尾。如果 `index` 比长度更大，该节点将 **不会插入** 到链表中。
>- `void deleteAtIndex(int index)` 如果下标有效，则删除链表中下标为 `index` 的节点。

**示例：**

```
输入
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
输出
[null, null, null, null, 2, null, 3]

解释
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
myLinkedList.get(1);              // 返回 2
myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
myLinkedList.get(1);              // 返回 3
```

 

**提示：**

- `0 <= index, val <= 1000`
- 请不要使用内置的 LinkedList 库。
- 调用 `get`、`addAtHead`、`addAtTail`、`addAtIndex` 和 `deleteAtIndex` 的次数不超过 `2000` 。

## 题目大意

>这道题⽐较简单，设计⼀个链表，实现相关操作即可。

## 解题思路

>这题有⼀个地⽅⽐较坑，题⽬中 Note ⾥⾯写的数值取值范围是 [1, 1000]，笔者把 0 当做⽆效值。结果 case ⾥⾯出现了 0 是有效值。case 和题意不符。

## 代码

```c++
/*
 * @Author: Jean_Leung
 * @Date: 2024-09-16 17:11:13
 * @LastEditors: Jean_Leung
 * @LastEditTime: 2024-09-16 18:10:00
 * @FilePath: \code\link_list_leetcode707.cpp
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

class MyLinkedList {
  public:
    struct LinkedNode {
        int val;
        LinkedNode *next;
        LinkedNode(int val) : val(val), next(nullptr) {}
    };
    // 构造函数
    MyLinkedList() {
        dummy_head = new LinkedNode(0);
        size = 0;
    }
    /**
     * @description: 获得index位置的值
     * @param {int} index
     * @return {*}
     */
    int get(int index) {
        // 如果index的值是大于链表长度或者小于0，则返回-1
        if (index > (size - 1) || index < 0) {
            return -1;
        }
        LinkedNode *p = dummy_head->next; // 真正的头节点，不是虚拟节点
        while (index--) {
            p = p->next; // 继续遍历链表
        }
        return p->val;
    }

    /**
     * @description: 在链表第一个结点位置添加元素
     * @param {int} val
     * @return {*}
     */
    void addAtHead(int val) {
        // 直接插在虚拟头结点后面
        LinkedNode *p = dummy_head->next;    // 真正的头节点
        LinkedNode *q = new LinkedNode(val); // 创建结点
        dummy_head->next = q;
        q->next = p;
        size++;
    }
    /**
     * @description: 在链表尾部添加结点
     * @param {int} val
     * @return {*}
     */
    void addAtTail(int val) {
        // 需要找到尾部最后元素位置
        LinkedNode *p = dummy_head;          // 真正头节点
        LinkedNode *q = new LinkedNode(val); // 创建临时结点
        while (p->next) {
            p = p->next;
        }
        // 找到最后一个结点p
        // 在最后位置添加结点
        q->next = p->next;
        p->next = q;
        size++;
    }
    /**
     * @description: 在index位置之前添加结点
     * @param {int} index
     * @param {int} val
     * @return {*}
     */
    void addAtIndex(int index, int val) {
        // 如果index大于size的长度,那么不插入
        if (index > size) {
            return;
        }
        // 如果index刚好等于size-1
        if (index == size) {
            addAtTail(val);
            return;
        }
        // 如果index 小于0,相当于进行插入变成头节点
        if (index < 0) {
            index = 0;
        }
        LinkedNode *p = dummy_head;
        LinkedNode *q = new LinkedNode(val);
        // 找到插入位置的前个结点
        while (index--) {
            p = p->next;
        }
        q->next = p->next;
        p->next = q;
        size++;
    }
    /**
     * @description: 如果下标有效则删除下标为index的结点
     * @param {int} index
     * @return {*}
     */
    void deleteAtIndex(int index) {
        // 如果index < 0 且 index > size-1的时候
        // 下标无效，不用删除
        if (index < 0 || index > size - 1) {
            return;
        }
        LinkedNode *p = dummy_head; // 虚拟头节点
        // 找到需要删除的结点的前个结点
        while (index--) {
            p = p->next;
        }
        LinkedNode *temp = p->next; // 需要删除的结点
        p->next = temp->next;
        delete temp;
        temp = nullptr;
        size--;
    }

    // 打印链表
    void printLinkedList() {
        LinkedNode *cur = dummy_head;
        while (cur->next != nullptr) {
            std::cout << cur->next->val << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }

  private:
    int size;               // 链表长度
    LinkedNode *dummy_head; // 虚拟头节点
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main() {
    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2); // 链表变为 1->2->3
    // int ans = myLinkedList.get(1);           // 返回 2
    myLinkedList.deleteAtIndex(1); // 现在，链表变为 1->3
    // myLinkedList.get(1);           // 返回 3
    myLinkedList.printLinkedList();
    return 0;
}
```

# 206 [反转链表](https://leetcode.cn/problems/reverse-linked-list/description/)

## 题目

>给你单链表的头节点 `head` ，请你反转链表，并返回反转后的链表。

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg)

```
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg)

```
输入：head = [1,2]
输出：[2,1]
```

**示例 3：**

```
输入：head = []
输出：[]
```

 

**提示：**

- 链表中节点的数目范围是 `[0, 5000]`
- `-5000 <= Node.val <= 5000`



**进阶：**链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？

## 题目大意

按照题目来做即刻

## 解题思路

按照题目来做即刻，没有特殊的思路

## 代码

```c++
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

```

