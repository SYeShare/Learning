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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr || l2 == nullptr)
        {
            return l1 == nullptr ? l2 : l1;
        }
        ListNode *node = new ListNode(0);
        ListNode *head = node;
        int sum = 0;
        bool bcarry = false;

        while (l1 != nullptr || l2 != nullptr)
        {
            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            if (bcarry)
            {
                sum += 1;
            }
            node->next = new ListNode(sum % 10);
            bcarry = sum >= 10 ? true : false;
            node = node->next;
            sum = 0;
        }
        if (bcarry)
        {
            node->next = new ListNode(1);
        }
        return head->next;
    }
};