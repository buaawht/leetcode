//
// Created by buaawht on 2019-02-12.
//


/*
 *
206. Reverse Linked List
        Easy
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
        Output: 5->4->3->2->1->NULL
        Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?*/


#include "util.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    ListNode* getLastNode(ListNode* rear) {
        if (rear == nullptr || rear->next == nullptr) {
            return rear;
        }

        ListNode* tmp = getLastNode(rear->next);
        tmp->next = rear;
        return rear;
    }

    /**
     * 递归版本1
     * @param head
     * @return
     */
    ListNode *reverseList1(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // 最后一个非空节点
        ListNode* p = head;
        while (p->next != nullptr) {
            p = p->next;
        }

        // 递归
        ListNode *rear = getLastNode(head);
        // 最后节点的next需要设置null
        rear->next = nullptr;
        return p;
    }

    /**
     * 迭代版本
     * @param head
     * @return
     */
    ListNode *reverseList2(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // 1-2-3-4
        // pre-curr-next
        ListNode *rear = head;
        ListNode *curr = rear->next;

        while (curr != nullptr) {
            ListNode *next = curr->next;
            curr->next = head;
            head = curr;
            rear->next = next;
            curr = rear->next;
        }

        return head;
    }

    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *tmp = reverseList(head->next);

        head->next->next = head;
        head->next = nullptr;

        return tmp;
    }
};


int main() {
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    show_list_node(l1);

    Solution s;
    ListNode *res = s.reverseList(l1);
    show_list_node(res);

    return 0;
}
