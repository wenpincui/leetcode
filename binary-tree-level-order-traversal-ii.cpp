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
    void push_nodes(vector<vector<TreeNode *> > &nodes) {
        int size = nodes.size();
        vector<TreeNode *> last = nodes[size-1];
        vector<TreeNode *>  childs;

        for (vector<TreeNode *>::iterator iter = last.begin();
             iter != last.end(); iter++) {
            if ((*iter)->left)
                childs.push_back((*iter)->left);
            if ((*iter)->right)
                childs.push_back((*iter)->right);
        }

        if (childs.size() == 0)
            return;
        else {
            nodes.push_back(childs);
            push_nodes(nodes);
        }
    }

    void push_ans(vector<vector<int> > &ans, vector<vector<TreeNode *> > &nodes) {
        vector<TreeNode *> tmp;

        while (nodes.size() != 0) {
            tmp = nodes[nodes.size() - 1];
            nodes.pop_back();
            vector<int> vals;
            for (vector<TreeNode *>::iterator iter = tmp.begin();
                 iter != tmp.end(); iter++) {
                vals.push_back((*iter)->val);
            }
            ans.push_back(vals);
            vals.clear();
        };
    }

    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ans;
        vector<vector<TreeNode *> > nodes;

        if (root == NULL)
            return ans;

        vector<TreeNode *> tmp;
        tmp.push_back(root);
        nodes.push_back(tmp);
        push_nodes(nodes);
        push_ans(ans, nodes);

        return ans;
    }
};
