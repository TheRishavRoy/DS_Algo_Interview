/*
Label: LC Medium, but very Easy and straight forward.

- Simple DP , just to memoize the solution and avoid redundant calls
- Use dp.resize(n, -1); instead of writing memset: memset(dp, -1, sizeof(dp)) . Thats because memset works at the byte level, and -1 is not the correct representation for long long values.
- After that simple recursion+backtracking i.e. take or not takr problem.
- We need to be carefull while taking next idx we don't go out of bound.
*/
class Solution {
public:
    vector<long long> dp;
    long long solve(int idx, int n, vector<vector<int>>& questions)
    {
        if(idx>=n)
        {
            return 0;
        }
        if(dp[idx]!=-1)
            return dp[idx];
        //if we take this question
        long long nextIdx=idx+questions[idx][1]+1;
        long long take=questions[idx][0];
        if(nextIdx<n)//need to make sure we can call next idx
            take+=solve(nextIdx,n,questions);
        
        long long notTake=solve(idx+1,n,questions);

        return dp[idx] = max(take, notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) 
    {
        long long points=0;
        int n=questions.size();
        dp.resize(n, -1);//not using memset for long long it is okay for int
        points=solve(0,n,questions);
        return points;
    }
};
