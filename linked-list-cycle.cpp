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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;

        ListNode *fast = head->next->next;
        ListNode *slow = head;

        while (1) {
            if (fast == NULL || slow == NULL || fast->next == NULL)
                return false;
            if (fast == slow)
                return true;
            fast = fast->next->next;
            slow = slow->next;
        }
    }
};
