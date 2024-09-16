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