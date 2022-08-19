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
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *cur = head;
        ListNode *next = head;
        while (cur)
        {
            for (int i = 0; i < k; i++)
            {
                if (next == nullptr)
                    return dummy->next;
                next = next->next;
            }
            ListNode *p = cur;
            ListNode *q = next;
            for (int i = 0; i < k; i++)
            {
                ListNode *t = p->next;
                p->next = q;
                q = p;
                p = t;
            }
            pre->next = q;
            pre = cur;
            cur = next;
        }
        return dummy->next;
    }
};