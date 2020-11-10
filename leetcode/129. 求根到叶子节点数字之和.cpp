/*2020-10-29 12:40:36
给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
例如，从根到叶子节点路径 1->2->3 代表数字 123。
计算从根到叶子节点生成的所有数字之和。
说明: 叶子节点是指没有子节点的节点。
链接：https://leetcode-cn.com/problems/sum-root-to-leaf-numbers
*/

#include "origin.hpp"

class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        return helper(root, 0);
    }

    int helper(TreeNode *node, int tmp)
    {
        if (node == NULL)
        {
            return 0;
        }
        tmp = tmp * 10 + node->val;
        if (node->left == NULL && node->right == NULL)
            return tmp;

        return helper(node->left, tmp) + helper(node->right, tmp);
    }
};