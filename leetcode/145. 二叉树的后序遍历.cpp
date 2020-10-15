/*
 * @Date: 2020-10-13 19:37:48 
 * @Last Modified time: 2020-10-13 19:37:48 
 */
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
//����1����������ǰ�� ������ ��΢����Ϊ ������Ȼ��ת �ɺ��� ���Ҹ�
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
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
                node = node->right;
            }
            node = st.top();
            st.pop();
            node = node->left;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};