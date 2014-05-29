/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyNode(RandomListNode *node,
                             map<RandomListNode *, RandomListNode *> &copyed) {
        if (copyed.find(node) != copyed.end())
            return copyed[node];
        RandomListNode *newNode = new RandomListNode(node->label);
        copyed[node] = newNode;
        if (node->next)
            newNode->next = copyNode(node->next, copyed);
        if (node->random)
            newNode->random = copyNode(node->random, copyed);
        return newNode;
    }

    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;

        map<RandomListNode *, RandomListNode *> copyed;
        RandomListNode *node = head;

        return copyNode(head, copyed);
    }
};
