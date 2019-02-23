//
// Created by buaawht on 2019-02-23.
//

//给定两个有序链表的头指针head1和head2，打印出两个链表的公共部分

#import "util.h"
class Solution {
public:
    void printCommonList(ListNode *head1, ListNode *head2) {
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val == head2->val) {
                cout << head2->val << endl;
                head1 = head1->next;
                head2 = head2->next;
            } else if (head1->val > head2->val) {
                head2 = head2->next;
            } else {
                head1 = head1->next;
            }
        }
    }
};

int main() {

    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    l2->next->next->next = new ListNode(8);

    Solution solution;
    solution.printCommonList(l1, l2);

}