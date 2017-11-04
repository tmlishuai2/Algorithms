/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* t1 = head;
        int length = 0;
        while(t1 != NULL)
        {
            t1 = t1->next;
            ++length;
        }
        int pos = length - n;
        if(pos == 0)
        {
            head = head->next;
            return head;
        }
        else
        {
            t1 = head;
            for(int i = 1; i < pos; i++)
            {
                t1 = t1->next;
            }
        }
        t1->next = t1->next->next;
        return head;
    }
};