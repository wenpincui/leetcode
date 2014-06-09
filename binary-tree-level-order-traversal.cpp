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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        if (root == NULL)
            return ans;

        queue<TreeNode *> q1;
        queue<TreeNode *> q2;

        q1.push(root);
        while (1) {
            vector<int> tmp;
            while (!q1.empty()) {
                TreeNode *cur = q1.front();
                q1.pop();
                tmp.push_back(cur->val);
                if (cur->left)
                    q2.push(cur->left);
                if (cur->right)
                    q2.push(cur->right);
            }
            ans.push_back(tmp);
            if (q2.empty())
                break;
            else
                swap(q1, q2);
        }

        return ans;
    }
};
