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
//Approach 2: Recursion
class Solution {
public:
   ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
			return head;
			
		ListNode* newHead=reverseList(head->next);//this will be the new head(Lst Node) at the top of call stack
		
		//after this, while tracing back call stack, we only do the following:
		
		head->next->next=head;// 4->5 becomes 5->4 reverses the pointer
		head->next=nullptr;//we make it null since we no longer need it. It will anyway get assigned a next pointer in the call stack.
		//also the first node will now have ->next as nullptr
		
		return newHead;
    }
};
