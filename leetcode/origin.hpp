#ifndef _ORIGIN_HPP
#define _ORIGIN_HPP

#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm> //用于字符串、容器、数组 的逆序（反转）
#include <string.h>
#include <unordered_map>

#include <stdio.h>
#include <arpa/inet.h>

using namespace std;

//test
namespace UserTest
{
    void usertest();
};

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

#endif