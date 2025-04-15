class Solution {
public:
    bool isValid(string s) {
        int len=s.size();
        stack <char> stk;
        for(int i=0;i<len;i++)
        {
            if(s[i]==')'||s[i]=='}'||s[i]==']')//at first we elemenate any possibilty of invalid string starting with close brases. 
            //also if there is closing braces in the midle of the strin that does not have opening braces, will be caught here.
            {
                if(stk.empty()==true)//if stack is empty and string starts with close parenthesis. string invalid.
                {
                    return false;//return false
                }
            }
            if(s[i]=='('||s[i]=='{'||s[i]=='[')////then we push any opening braces on stack
            {
                stk.push(s[i]);
            }
            //now we start checking balance of parenthesis:
            else if(s[i]==')')
            {
                char tp=stk.top();
                stk.pop();
                if(tp=='(')//every close brases should have opening braces. it will only reflect on top of the stack.
                {
                    continue;//still balanced. continue to next element .
                }
                else
                {
                    return false;//stop operation. not balanced. return false.
                }
            }
            else if(s[i]=='}')//repeat for '}'
            {
                char tp=stk.top();
                stk.pop();
                if(tp=='{')
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
            else if(s[i]==']')//repeat for ']'
            {
                char tp=stk.top();
                stk.pop();
                if(tp=='[')
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        if(stk.empty()==true)//is stack gets cleared then all braces are balanced
            return true;
        else
            return false;//else there is a opening braces that does not have closing braces.
    }
}; 
