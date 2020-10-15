/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include "origin.hpp"

//�ǵݹ飬��ͳһ�����ͷ�ͳһ����

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *node = root;

        while (node || !st.empty())
        {
            while (node != nullptr)
            {
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            res.emplace_back(node->val);
            node = node->right;
        }
        return res;
    }
};