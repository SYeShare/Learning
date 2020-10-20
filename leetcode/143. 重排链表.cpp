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