#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        vector<TreeNode *> nodes;

        if (root == NULL)
            goto out;

        nodes.push_back(root);

        walk(nodes, 0, ret);
    out:
        return ret;
    }

    void walk(vector<TreeNode *> nodes, int level, vector<vector<int> > &ret) {
        if (nodes.size() == 0)
            return;

        int dir = level&1;
        vector<TreeNode *> childs;
        vector<int> val;
//        printf("level %d, dir %d\n", level, dir);

        for (int i = nodes.size() - 1; i != -1; i--) {
            TreeNode *node = nodes[i];
            val.push_back(node->val);
            push_child(node, childs, dir);
        }

        ret.push_back(val);
        walk(childs, level + 1, ret);
    }

    void push_child(TreeNode *node, vector<TreeNode *> &childs, int dir) {
        if (dir == 0) {
            if (node->left != NULL)
                childs.push_back(node->left);
            if (node->right != NULL)
                childs.push_back(node->right);
        } else {
            if (node->right != NULL)
                childs.push_back(node->right);
            if (node->left != NULL)
                childs.push_back(node->left);
        }
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    vector<vector<int> > ret;
    vector<vector<int> >::iterator iter;
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(4);
    TreeNode t5(5);

    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t3.right = &t5;

    ret = sol.zigzagLevelOrder(&t1);

    for (iter = ret.begin(); iter != ret.end(); iter++) {
        vector<int> item = *iter;
        vector<int>::iterator iter2;
        printf("[");
        for (iter2 = item.begin(); iter2 != item.end(); iter2++)
            printf("%d ", *iter2);
        printf("]\n");
    }

    return 0;
}
