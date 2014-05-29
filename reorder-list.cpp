#include <stack>
#include <cstdio>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
class Solution {
public:
    void reorderList(ListNode *head) {
        int len = 0;
        ListNode *node = head;
        stack<ListNode *> s;

        if (head == NULL)
            return;
        while (node != NULL) {
            len++;
            s.push(node);
            node = node->next;
        }

        node = head;
        ListNode *node2 = s.top();
        s.pop();
        while (node != node2) {
            ListNode *nnext = node->next;
            node->next = node2;
            if (nnext == s.top()) {
                node2->next = nnext;
                nnext->next = NULL;
                break;
            }

            if (nnext == node2) {
                node2->next = NULL;
                break;
            }

            node2->next = nnext;
            node2 = s.top();
            s.pop();
            node = nnext;
        }
    }
};

int main(int argc, char **argv)
{
    struct ListNode n0(0), n1(1), n2(2), n3(3);
    Solution sol;

    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;

    sol.reorderList(&n0);

    for (struct ListNode *p = &n0; p != NULL; p = p->next)
        printf("%d\n", p->val);

    return 0;
}
