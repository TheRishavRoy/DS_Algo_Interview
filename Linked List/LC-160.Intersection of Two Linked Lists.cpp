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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {       
		while(headA != nullptr)//move A one by one
		{
			ListNode* ptrB=headB;//trace entire B for each node in A , 
            //otherwise if we move simultaneously we might miss the intersection point
			while(ptrB!=NULL)
			{
				if(headA==ptrB)
					return ptrB;//found it
				ptrB=ptrB->next;
			}
			headA=headA->next;
		}
		
		return nullptr;//no intersection
    }
};
