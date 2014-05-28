#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool judge(TreeNode *root, int min1, int max1) {
        if ((root->val <= min1 && min1 != INT_MIN)
            || (root->val >= max1 && max1 != INT_MAX))
            return false;

        if (root->left) {
            if (judge(root->left, min1, min(max1, root->val)) == false)
                return false;
        }

        if (root->right) {
            if(judge(root->right, max(min1, root->val), max1) == false)
                return false;
        }

        return true;
    }

    bool isValidBST(TreeNode *root) {
        if (root == NULL)
            return true;
        if (root->left == NULL && root->right == NULL)
            return true;

        int val = root->val;
        bool ret = true;

        if (root->left) {
            if (root->left->val >= val)
                return false;
            else
                ret = judge(root->left, INT_MIN, val);
        }
        if (ret == false)
            return false;

        if (root->right) {
            if (root->right->val <= val)
                return false;
            else
                ret = judge(root->right, val, INT_MAX);
        }

        return ret;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    TreeNode n0(10), n1(5), n2(15), n3(6), n4(20);

    n0.left = &n1;
    n0.right = &n2;
    n2.left = &n3;
    n2.right = &n4;
    cout<<sol.isValidBST(&n0)<<endl;
}
