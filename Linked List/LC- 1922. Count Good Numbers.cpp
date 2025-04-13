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
    void reorderList(ListNode* head) {
        if(!head) 
            return;

        vector<int> nums;
        ListNode* traverse = head;
        while (traverse != nullptr) 
        {
            nums.push_back(traverse->val);//storing it in vector for easier acess to val of each node
            traverse = traverse->next;
        }

        int i = 0, j = nums.size() - 1;//idx to front and back of nums
        traverse = head;//reusing the pointer
        bool pickFromFront = true;//this switches alternately

        while (traverse != nullptr) 
        {
            if (pickFromFront) 
            {
                traverse->val = nums[i++];//assign value and increment idx
            } 
            else 
            {
                traverse->val = nums[j--];//assign value ans decrement idx
            }
            pickFromFront = !pickFromFront;//alter it for next iteration
            traverse = traverse->next;//next node to be modifies in LL
        }
    }
};
