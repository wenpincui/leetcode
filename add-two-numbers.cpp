#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

class Solution {
public:
    ListNode *addWithOverFlow(ListNode *l1, ListNode *l2, int overflow) {
        ListNode *next = NULL;
        ListNode *n1 = NULL;
        ListNode *n2 = NULL;
        int val = 0;
        if (l1) {
            val += l1->val;
            next = l1;
            n1 = l1->next;
        }
        if (l2) {
            val += l2->val;
            next = l2;
            n2 = l2->next;
        }

        val += overflow;
        if (val >= 10) {
            overflow = 1;
            val -= 10;
        } else
            overflow = 0;

        if (next == NULL && val == 0)
            return NULL;
        else if (next == NULL && val != 0) {
            next = new ListNode(val);
            return next;
        } else {
            next->val = val;
            next->next = addWithOverFlow(n1, n2, overflow);
            return next;
        }

    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        return addWithOverFlow(l1, l2, 0);
    }
};

int main(int argc, char **argv)
{
    struct ListNode n0(2), n1(4), n2(3);
    struct ListNode n3(5), n4(6), n5(8);

    n0.next = &n1;
    n1.next = &n2;

    n3.next = &n4;
    n4.next = &n5;

    Solution sol;
    struct ListNode *ans = sol.addTwoNumbers(&n0, &n3);

    while (ans != NULL) {
        cout<<ans->val<<endl;
        ans = ans->next;
    }

    return 0;
}
