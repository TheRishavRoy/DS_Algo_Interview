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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if (!head || k == 1)
            return head;

        // Check if there are at least k nodes to reverse
        ListNode* nodeCountptr = head;
        for (int i = 0; i < k; ++i) 
        {
            if (!nodeCountptr)
                return head;//no need to reverse
            nodeCountptr = nodeCountptr->next;
        }

        // Reverse k nodes
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;

        for (int i = 0; i < k; ++i) 
        {
            nxt = cur->next;//store next pointer so we don't loose it
            cur->next = prev;//reverse list
            prev = cur;//update prev
            cur = nxt;//update cur
        }

        // Recursive call for the remaining list
        head->next = reverseKGroup(cur, k);

        return prev;
    }
};

