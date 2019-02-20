/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/

#include "util.h"

class Solution {
public:
	ListNode *reverseList(ListNode *head, int m, int n) {
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}

		ListNode *rear = head;
		ListNode *cur = rear->next;
		ListNode p = head;

		int i = 1;
		while(cur != nullptr) {
			if ( i < m ) {
				
			}
		}

	}
}
