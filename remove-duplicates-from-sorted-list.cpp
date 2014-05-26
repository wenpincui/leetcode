#include <stdio.h>

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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL)
            return NULL;
        ListNode *cur = head;
        ListNode *p = head;

        while (cur != NULL) {
            p = cur->next;
            while (p != NULL && p->val == cur->val) {
                p = p->next;
            }
            cur->next = p;
            cur = p;
        }

        return head;
    }
};
