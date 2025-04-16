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

 //Always use nullptr instead of NULL in modern C++ (C++11 and later) because: nullptr is type-safe. It avoids ambiguity between integer 0 and null pointers.

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);//we use a dummy node since our first current node has not been created yet
        ListNode* curr=dummyHead;//so initially cur is a dummy. Later when we add first digits cur gets updated.
        int carry=0;
        int digit1,digit2,sum;

        //since digits are stored inreverse order we traverse fron left to right of LL itself while adding
        while(l1!=NULL || l2!=NULL ||carry!=0)
        {
            digit1=l1?l1->val:0;
            digit2=l2?l2->val:0;
            sum=digit1+digit2+carry;
            carry=sum/10;
            curr->next=new ListNode(sum%10);
            curr=curr->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummyHead->next;//The actual result starts from dummyHead->next
    }
};
