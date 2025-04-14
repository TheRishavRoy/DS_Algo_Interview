class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        stack<int> reverse;
        ListNode* traverse=head;
		while(traverse!=nullptr)
		{
			reverse.push(traverse->val);//pushing into the stack
			traverse=traverse->next;
		}
		//now stack has nodes in reverse order : top to bottom
		traverse=head;//reusing
		while(traverse!=nullptr)
		{
			int val=reverse.top();
			reverse.pop();
			if(val!=traverse->val)
				return false;
				
			traverse=traverse->next;
		}
		return true;
    }
};
