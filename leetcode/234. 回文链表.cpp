/**
请判断一个链表是否为回文链表。
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 */
#include "origin.hpp"
class Solution
{
public:
    //2020-10-23 12:37:27
    //破坏原链表
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return true;

        //find mid
        int count = 0;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            count++;
        }

        //反转后半部分
        ListNode *midnode = slow->next;
        slow->next = nullptr;

        ListNode *pre = nullptr;
        ListNode *curr = midnode;
        while (curr)
        {
            ListNode *tmp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = tmp;
        }

        //compare
        ListNode *phead = head;
        while (pre)
        {
            if (pre->val != phead->val)
            {
                return false;
            }
            pre = pre->next;
            phead = phead->next;
        }
        return true;
    }
};