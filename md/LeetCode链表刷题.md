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

# 24 [两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/description/)

## 题目

>给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg)

```
输入：head = [1,2,3,4]
输出：[2,1,4,3]
```

**示例 2：**

```
输入：head = []
输出：[]
```

**示例 3：**

```
输入：head = [1]
输出：[1]
```

 

**提示：**

- 链表中节点的数目在范围 `[0, 100]` 内
- `0 <= Node.val <= 100`

## 题目大意

两两相邻的元素，翻转链表

## 解题思路

>按照题意做即可

![](https://pic.superbed.cc/item/66ea653f2e3b94edab37807c.png)

## 代码

```c++
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
```

# 19 [删除链表的倒数第N个节点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/)

## 题目

>给你一个链表，删除链表的倒数第 `n` 个结点，并且返回链表的头结点。

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg)

```
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
```

**示例 2：**

```
输入：head = [1], n = 1
输出：[]
```

**示例 3：**

```
输入：head = [1,2], n = 1
输出：[1]
```

 

**提示：**

- 链表中结点的数目为 `sz`
- `1 <= sz <= 30`
- `0 <= Node.val <= 100`
- `1 <= n <= s`

## 题目大意

>删除链表中倒数第 n 个结点。

## 解题思路

>这道题⽐较简单，先循环⼀次拿到链表的总⻓度，然后循环到要删除的结点的前⼀个结点开始删除操作。需要注意的⼀个特例是，有可能要删除头结点，要单独处理。
>
>这道题有⼀种特别简单的解法。设置 2 个指针，⼀个指针距离前⼀个指针 n 个距离。同时移动 2 个指针，2 个指针都移动相同的距离。当⼀个指针移动到了终点，那么前⼀个指针就是倒数第 n 个节点了。

## 代码

```c++
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
```



# 面试题 [链表相交](https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/description/)

## 题目

>给你两个单链表的头节点 `headA` 和 `headB` ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 `null` 。
>
>图示两个链表在节点 `c1` 开始相交**：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_statement.png)

题目数据 **保证** 整个链式结构中不存在环。

**注意**，函数返回结果后，链表必须 **保持其原始结构** 。

**示例 1：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_example_1.png)

```
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Intersected at '8'
解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。
在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
```

**示例 2：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_example_2.png)

```
输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Intersected at '2'
解释：相交节点的值为 2 （注意，如果两个链表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。
在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
```

**示例 3：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_example_3.png)

```
输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。
由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
这两个链表不相交，因此返回 null 。
```

- `listA` 中节点数目为 `m`
- `listB` 中节点数目为 `n`
- `0 <= m, n <= 3 * 104`
- `1 <= Node.val <= 105`
- `0 <= skipA <= m`
- `0 <= skipB <= n`
- 如果 `listA` 和 `listB` 没有交点，`intersectVal` 为 `0`
- 如果 `listA` 和 `listB` 有交点，`intersectVal == listA[skipA + 1] == listB[skipB + 1]`

## 题目大意

>就是找到两条链表的公共入口点

## 解题思路

>解题思路:
>
>- 计算链A和链B的长度，计算两者差值move_step，比较谁是长链，谁是短链
>- 然后长链头指针先走move_step
>- 然后两者的指针同时走，同时每次判断走的地方是否指针相同
>  - 如果相同，则返回该指针
>  - 如果不相同，继续走下一步，直到结束循环找不到相同指针，则返回NULL



## 代码

```c++
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

```

# 142 [找到环的入口处](https://leetcode.cn/problems/linked-list-cycle-ii/)

## 题目

>给定一个链表的头节点  `head` ，返回链表开始入环的第一个节点。 *如果链表无环，则返回 null。*
>
>如果链表中有某个节点，可以通过连续跟踪 `next` 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 `pos` 来表示链表尾连接到链表中的位置（**索引从 0 开始**）。如果 `pos` 是 `-1`，则在该链表中没有环。**注意：pos 不作为参数进行传递**，仅仅是为了标识链表的实际情况。
>
>**不允许修改** 链表

**示例一**

![img](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png)

```
输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点
```

**示例二**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test2.png)

```
输入：head = [1,2], pos = 0
输出：返回索引为 0 的链表节点
解释：链表中有一个环，其尾部连接到第一个节点。
```

**示例三**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test3.png)

```
输入：head = [1], pos = -1
输出：返回 null
解释：链表中没有环。
```

**提示：**

- 链表中节点的数目范围在范围 `[0, 104]` 内
- `-105 <= Node.val <= 105`
- `pos` 的值为 `-1` 或者链表中的一个有效索引

## 题目大意

>- 假如该链表有环，则需要找到环入口处
>- 如果没有环，则返回NULL

## 解题思路

>参照代码随想录的数学证明方法



## 代码

```c++
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
```

