/*
//T.C : O(n * 3 * 2^(n-1)) ~= O(n*2^n)
//S.C : O(n * 2^n) , total 2^n strings eaching having length n

Using standard backtrackin technique/template:
-keep generating all happy string and storing in a string name cur. 
-keep storing all happy string of length n in a vector<string> called result. Stored once base case is met:cur.length()==n (means we have found a happy string of len = n)
-While generating happy string we use only (concatinate only) a,b,c.
-Then we Do:take ch(a,b,c) and add to cur
- Explore: call solve function with cur
- Undo: remove ch from cur
*/
class Solution {
public:
    void solve(int n, string &cur, vector<string> &result)
    {
        if(cur.length()==n)//if we have made a happy string of length n already
        {
            result.push_back(cur);//push it to result
            return;
        }
        for (char ch = 'a'; ch <= 'c'; ch++)//we have to add from 'a','b','c' only
        {
            if(!cur.empty() && cur.back()==ch/*same character*/)
                continue;//skip this character
            
            //follow standard backtracking:

            // 1. Do (take this character)
            cur.push_back(ch);

            // 2. Explore (explore with this)
            solve(n, cur, result);

            // 3. Undo (complete doing backtrack)
            cur.pop_back();
        }
        //we only return when we reach len==n, this a void function 
    }
    string getHappyString(int n, int k) 
    {
        string cur="";//current generated string

        vector<string> result;
        solve(n, cur, result);
        if(result.size()<k)//if number of string pushed into result is less than k
            return "";

        return result[k-1];//kth smallest is at index k-1 of vector result;

    }
};
