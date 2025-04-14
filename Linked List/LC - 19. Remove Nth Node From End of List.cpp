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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head)
            return nullptr;

        ListNode* traverse=head;
        int len=0;//length of linked list

        while(traverse!=nullptr)
        {
            ++len;//increment length
            traverse=traverse->next;
        }

        if(len==1)//if length is 1 then it will become 0
            return nullptr;//so return nullptr

        int target=len-n+1;//find target location
        ListNode* cur=head;//current
        ListNode* prev=nullptr;//keep a previous pointer for cur
        
        while(cur!=nullptr && target!=0)
        {
            if(target==1)//got our node that is to be removed
            {
                if(cur == head)//handling corner case where we have to remove first node of LL
                {
                    head = cur->next;
                    cur->next=nullptr;
                }
                if(prev)//avoid seg fult
                    prev->next=cur->next;
            }
            --target;//continiue to reach target
            prev=cur;//update previous
            cur=cur->next;//update current
        }
        return head;
    }
};
