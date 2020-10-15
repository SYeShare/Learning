
#include "origin.hpp"
class Solution
{
public:
    Node *connect(Node *root)
    {
#if 1 //层次遍历  使用queue
        if (root == nullptr)
        {
            return root;
        }
        queue<Node *> que;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                Node *node = que.front();
                que.pop();
                if (i < size - 1)
                {
                    node->next = que.front();
                }
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
            }
        }
        return root;

#endif

#if 0 //递归
        if (root == nullptr || root->left == nullptr)
        {
            return root;
        }
        root->left->next = root->right;
        if (root->next != nullptr)
        {
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);

        return root;
#endif
    }
};