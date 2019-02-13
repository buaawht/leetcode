//
// Created by buaawht on 2019-02-12.
//

/*
You are given two non-empty linked lists representing two non-negative integers.
 The digits are stored in reverse order and each of their nodes contain a single digit.
 Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 */

#include "util.h"
#include <math.h>

class Solution {
public:
    /**
     * 先反转，再求和
     * @param l1
     * @param l2
     * @return
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    }

    /**
     * 整数会溢出，直白方法
     * @param l1
     * @param l2
     * @return
     */
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        int first = 0;
        int second = 0;
        int sum = 0;
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }

        ListNode* p1 = l1;
        int i = 0;
        show_list_node(p1);
        while (p1 != nullptr) {
            first = first + pow(10, i) * p1->val;
            p1 = p1->next;
            i++;
        }

        ListNode* p2 = l2;
        i = 0;
        while (p2 != nullptr) {
            second = second + pow(10, i) * p2->val;
            p2 = p2->next;
            i++;
        }
        sum = first + second;

        // 807
        // 7 --> 0 --> 8
        auto *res = new ListNode(sum % 10);
        auto rear = res;
        sum = sum / 10;
        while (sum > 0) {
            int remainder = sum % 10;
            ListNode *tmp = new ListNode(remainder);
            rear->next = tmp;
            rear = tmp;
            sum = sum/10;
        }
        show_list_node(res);
        return res;
    }
};

int main() {
    ListNode l1(2);
    l1.next = new ListNode(4);
    l1.next->next = new ListNode(3);

    ListNode l2(5);
    l2.next = new ListNode(6);
    l2.next->next = new ListNode(4);

    Solution s;
    ListNode *res = s.addTwoNumbers(&l1, &l2);
    show_list_node(res);

    return 0;
}

