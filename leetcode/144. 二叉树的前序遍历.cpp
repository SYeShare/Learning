/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "origin.hpp"

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *node = root;

        while (node || !st.empty())
        {
            while (node)
            {
                res.emplace_back(node->val);
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            node = node->right;
        }
        return res;
    }
};