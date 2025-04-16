class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n);//create a result vector of size n
        stack<int> stk;
        for (int i = 0; i < n; ++i) 
        {
            while (!stk.empty() && temperatures[stk.top()] < temperatures[i])//if satck is non empty && tempearture on top of stack is less than current temperature. update the same for the top of the stack.
            {
                ans[stk.top()] = i - stk.top();//these many days it will take for "stk.top()" to come to "i", "i" is warmer
                stk.pop();//since st.top() is now calculated
            }
            stk.push(i);//if stack is empty or present temperature need to be recorded any way for future. we still have to find warmer day than "i"
        }
        return ans;//return answer
    }
};
