// 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
// 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include "origin.hpp"

class Solution_Sec
{
public:
    void reorderList(ListNode *head)
    {
        //check
        if (head == nullptr || head->next == nullptr)
            return;

        ListNode *slow = head, *fast = head;

        //find mid node;
        ListNode *midnode = findmidnode(slow, fast);
        //reverse right part lsit;
        ListNode *revernode = reversenode(midnode);

        ListNode *p = head;
        while (revernode)
        {
            ListNode *headnext = p->next;
            ListNode *revernext = revernode->next;
            p->next = revernode;
            revernode->next = headnext;
            p = headnext;
            revernode = revernext;
        }
    }

    ListNode *findmidnode(ListNode *slow, ListNode *fast)
    {
        while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *midnode = slow->next;
        slow->next = nullptr;
        return midnode;
    }
    ListNode *reversenode(ListNode *root)
    {
        ListNode *pre = nullptr;
        ListNode *cur = root;
        while (cur)
        {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr)
        {
            return;
        }
        ListNode *node = head;
        ListNode *p = head, *q = head; //快慢指针
        while (q->next)
        {
            p = p->next;
            q = q->next;
            if (q->next)
            {
                q = q->next;
            }
        }
        q = p->next;
        p->next = nullptr;
        //找到了中间节点，反转后半段的链表
        ListNode *newnode = reserve(q);

        //链接新的链表
        while (newnode)
        {
            ListNode *headnext = head->next, *newnodenext = newnode->next;
            head->next = newnode;
            newnode->next = headnext;
            head = headnext;
            newnode = newnodenext;
        }
    }

    ListNode *reserve(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *node = head;
        while (node)
        {
            ListNode *next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
};