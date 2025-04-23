class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int maxLen = 0;
        int lastInvalid = -1;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(') 
            {
                stk.push(i);//we store it for future
            } 
            else //s[i]==')'
            {
                if (!stk.empty())//There's a '(' to match the current s[i]== ')' 
                //since we only push when s[i]=='(' in Line 12
                {
                    // There's a '(' available to match the current ')' because:
                    // We only push indices of '(' into the stack.
                    // So if the stack is not empty, the top must be a '(' (its index).

                    stk.pop(); // We match the current ')' with the most recent unmatched '(' and remove it.
                    if (!stk.empty()) 
                    {
                // There are still unmatched '(' before this, so the valid substring starts after the top of the stack.
                        maxLen = max(maxLen, i - stk.top());
                    } 
                    else 
                    {
                        // No unmatched '(', so the valid substring starts after the last unmatched ')'
                        maxLen = max(maxLen, i - lastInvalid);
                    }
                } 
                else //There was no '(' to match this ')' → invalid closing
                {
                    lastInvalid = i;//we update lastInvalid to mark this as a boundary for the next valid substring
                    //next valid length counting starts from current i
                }
            }
        }
        return maxLen;
    }
};
