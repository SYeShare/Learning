// 给定一个二叉树，找出其最小深度。
//     最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
//     说明 : 叶子节点是指没有子节点的节点。
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
class Solution_DFS
{
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int res = INT_MAX;
        dfs(root, 0, res);
        return res;
    }

    void dfs(TreeNode *root, int level, int &res)
    {
        level++;
        if (root->left == nullptr && root->right == nullptr)
        {
            res = min(res, level);
            return;
        }
        if (root->left)
        {
            dfs(root->left, level, res);
        }
        if (root->right)
        {
            dfs(root->right, level, res);
        }
    }
};

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        //递归
        if (root == nullptr)
            return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        return (left == 0 || right == 0) ? left + right + 1 : min(left, right) + 1;
    }
};