//
// Created by buaawht on 2019-02-23.
//

/**
 *
 *
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
 */

#include "util.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        ListNode *slow = head;
        int i = 0;

        if (head == nullptr) {
            return head;
        }
        for (int j = 0; j < n; ++j) {
            fast = fast->next;
        }

        if (fast == nullptr) {
            return head->next;
        }

        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return head;
    }

    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        if (head->next == nullptr)
            return nullptr;

        ListNode *pre = head, *cur = head;

        for (int i = 0; i < n; ++i)
            cur = cur->next;

        if (!cur)
            return head->next;

        while (cur->next) {
            cur = cur->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};

int main() {
    Solution s;

    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);
    show_list_node(l1);

    s.removeNthFromEnd(l1, 2);
    show_list_node(l1);
}

