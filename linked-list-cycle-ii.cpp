#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }

        return NULL;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    ListNode n0(3), n1(2), n2(0), n3(-4);
    ListNode *ans;

    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n1;

    ans = sol.detectCycle(&n0);
    if (ans == NULL) {
        printf("null\n");
        return 0;
    } else {
        printf("ans: %d\n", ans->val);
    }
}
