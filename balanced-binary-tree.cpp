#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void traverse(TreeNode *root, int *max_depth, int depth) {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL) {
            if (*max_depth <= depth)
                *max_depth = depth;
        }

        traverse(root->left, max_depth, depth + 1);
        traverse(root->right, max_depth, depth + 1);
    }

    bool isBalanced(TreeNode *root) {
        int left_depth = 0;
        int right_depth = 0;

        if (root == NULL)
            return true;

        if (root->left == NULL && root->right == NULL)
            return true;
        else if (root->left == NULL && root->right != NULL) {
            traverse(root->right, &right_depth, 0);
            if (right_depth > 0)
                return false;
            else
                return true;
        } else if (root->left != NULL && root->right == NULL) {
            traverse(root->left, &left_depth, 0);
            if (left_depth > 0)
                return false;
            else
                return true;
        } else {
            traverse(root->left, &left_depth, 0);
            traverse(root->right, &right_depth, 0);
            if (abs(left_depth - right_depth) <= 1)
                return isBalanced(root->left) && isBalanced(root->right);
            else
                return false;
        }
    }
};

int main(int argc, char **argv)
{
    Solution *sol = new Solution();
    TreeNode n0(0), n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7), n8(8);

    n0.left = &n1;
    n0.right = &n2;
    n1.left = &n3;
    n1.right = &n4;
    n3.left = &n5;
    n3.right = &n6;

//    n7.left = &n8;

    printf("ret %d\n", sol->isBalanced(&n0));

}
