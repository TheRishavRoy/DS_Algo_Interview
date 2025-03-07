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
    bool hasCycle(ListNode *head) {
        ListNode *fast=head;//fast pointer
        ListNode *slow=head;//slow pointer
        
        //why use fast->next!=NUL Also?
        //Ans: The fast pointer might already be at the last node. When the code tries to access fast->next->next, the first fast->next will be NULL.Accessing NULL->next would crash the program
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;//fast pointer iterate faster
            slow=slow->next;
            if(fast==slow)//if and when equal means we have found a cycle
                return true;//return true for cycle
        }
        return false;//otherwise in the end return no cycle
    }
};
