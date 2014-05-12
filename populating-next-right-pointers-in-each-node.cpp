#include <iostream>
#include <stdio.h>

using namespace std;

struct TreeLinkNode {
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *parent = root;
        TreeLinkNode *next_parent;

        if (root == NULL)
            return;
        root->next = NULL;

        while (parent != NULL) {
            next_parent = parent->left;
            while (parent != NULL && parent->left != NULL) {
                parent->left->next = parent->right;
                if (parent->next)
                    parent->right->next = parent->next->left;
                else
                    parent->right->next = NULL;
                parent = parent->next;
            }
            parent = next_parent;
        }
    }
};

int main(int argc, char **argv)
{
    TreeLinkNode t0, t1, t2, t3, t4, t5, t6;
    Solution *sol = new Solution();

    t0.left = &t1;
    t0.right = &t2;
    t1.left = &t3;
    t1.right = &t4;
    t2.left = &t5;
    t2.right = &t6;
    t3.left = NULL;
    t3.right = NULL;
    t4.left = NULL;
    t4.right = NULL;
    t5.left = NULL;
    t5.right = NULL;
    t6.left = NULL;
    t6.right = NULL;

    cout<<"here?"<<endl;
    sol->connect(&t0);

    printf("t0 %p, t1 %p, t2 %p, t3 %p\n", &t0, &t1, &t2, &t3);
    printf("t4 %p, t5 %p, t6 %p\n", &t4, &t5, &t6);
    printf("---------------\n");
    printf("t0.next %p\n", t0.next);
    printf("t1.next %p\n", t1.next);
    printf("t2.next %p\n", t2.next);
    printf("---------------\n");
    printf("t3.next %p\n", t3.next);
    printf("t4.next %p\n", t4.next);
    printf("t5.next %p\n", t5.next);
    printf("t6.next %p\n", t6.next);


    return 0;
}
