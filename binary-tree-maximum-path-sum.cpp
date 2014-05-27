#include <stdio.h>
#include <iostream>
#include <limits.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int find(TreeNode *root, bool inc) {
        int left_inc = INT_MIN;
        if (root->left)
            left_inc = find(root->left, true);
        int right_inc = INT_MIN;
        if (root->right)
            right_inc = find(root->right, true);

        if (!inc) {
            int ret = INT_MIN;
            int left = INT_MIN;
            int right= INT_MIN;
            if (root->left)
                left = max(find(root->left, false), left_inc);
            if (root->right)
                right = max(find(root->right, false), right_inc);
            return max(max(left, right), ret);
        } else {
            int ret = root->val;
            if (left_inc > 0)
                ret += left_inc;
            if (right_inc > 0)
                ret += right_inc;
            return ret;
        }
    }

    int maxPathSum(TreeNode *root) {
        return max(find(root, true), find(root, false));
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    TreeNode t0(1), t1(2), t2(3), t3(-3);

    t0.left = &t1;
    t0.right = &t2;

    printf("ans: %d\n", sol.maxPathSum(&t0));
}
