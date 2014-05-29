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
    void pre_tranverse(vector<int> &ans, TreeNode *node) {
        if (node == NULL)
            return;
        ans.push_back(node->val);
        if (node->left)
            pre_tranverse(ans, node->left);
        if (node->right)
            pre_tranverse(ans, node->right);
    }

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        pre_tranverse(ans, root);
        return ans;
    }
};
