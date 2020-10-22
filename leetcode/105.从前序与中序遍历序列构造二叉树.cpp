/**105. 从前序与中序遍历序列构造二叉树
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
    map<int, int> hash;
    vector<int> post;

    TreeNode *buildTree(int ps, int pe, int is, int ie)
    {
        if (ps > pe || is > ie)
        {
            return nullptr;
        }
        int root = post[ps];
        int pos = hash[root];

        TreeNode *node = new TreeNode(root);
        node->left = buildTree(ps + 1, ps + pos - is, is, pos - 1);
        node->right = buildTree(ps + pos - is + 1, pe, pos + 1, ie); //ps+pos-is+1 ��Ϊ+2����Ϊ�������Ѿ�����һ������ֻ����ê��λ�õ����ã�����ƫ��

        return node;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty() || inorder.empty())
        {
            return nullptr;
        }
        int tmp = 0;
        while (tmp < inorder.size())
        {
            hash[inorder[tmp]] = tmp;
            tmp++;
        }
        post = preorder;
        TreeNode *node = buildTree(0, preorder.size() - 1, 0, inorder.size() - 1); //size��С��Ҫȷ�ϣ���Ҫ��1����

        return node;
    }
};