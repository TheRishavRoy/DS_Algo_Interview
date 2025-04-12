/*

The Idea behind solution:
- After a cycle is detected using slow and fast pointer:

- L = distance from head to start of the cycle
- C = length of the cycle
- x = distance from cycle start to the point where slow and fast meet

- Fast moves twice the speed of slow:
    2 * (L + x) = L + x + n*C
   => L = n*C - x

- So if we start slow1 from head and slow from meeting point of slow&fast
  They will meet at L
  slow1 travels L distance
  slow travels n*C - x

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head -> next == NULL) 
            return NULL;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                ListNode* slow1=head;
                while(slow!=slow1)
                {
                    slow=slow->next;
                    slow1=slow1->next;
                }
                return slow;
            }

        }
        return NULL;
    }
};
