/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void post_tranverse(vector<int> &ans, TreeNode *node) {
        if (node == NULL)
            return;

        if (node->left)
            post_tranverse(ans, node->left);
        if (node->right)
            post_tranverse(ans, node->right);

        ans.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root == NULL)
            return ans;
        post_tranverse(ans, root);

        return ans;
    }
};
