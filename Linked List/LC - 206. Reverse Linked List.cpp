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
	        //This means ((head->next(5))->next) is now head, i.e. 5->next is now 4.
	        //That's it.
		head->next=nullptr;//we make it null since we no longer need it. 
	        //It will anyway get assigned a next pointer in the call stack.
		//also the first node will now have ->next as nullptr
	        //So 4->next is no longer 5, it is nullptr. In next call stack, 3->next is no longer 4, rather 4->next is 3 and 3->next becomes nullptr
	        //this goes on till 2->next is  1 and 1->next=nullptr;
		
		return newHead;// Return the same head found in base case, newHead remain the same across recursive calls (Last Node)
    }
};
