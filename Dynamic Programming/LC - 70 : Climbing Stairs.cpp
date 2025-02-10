/*
Description:

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
class Solution {
public:
    int climbStairs(int n) {
        //tabulation method. iterative methord.
        vector<int> dp(n+1,-1);//initializing dp table
        //for base case: The base case will be when we want to go to the 0th stair, then we have only one option(do nothing).
        //also, when on stais=1 we can take one step. So, dp[1] = 1 since we only have one choice

        dp[0]= 1;//If there are zero stairs, you are already at the top, and there is only one way to be there: doing nothing.
        dp[1]= 1;//If there is one stair, you can only reach it by taking one step.

    /*
    equation:
    dp[i]=dp[i−1]+dp[i−2]
    ======================    
    e.g. For n = 2 (Two stairs):

        dp[2]=dp[1]+dp[0]=1+1=2
	    You can reach step 2 by:
		    Taking two 1-steps: (1,1)
		    Taking one 2-step: (2)
    */
        for(int i=2; i<=n; i++)
        {
            dp[i] = dp[i-1]+ dp[i-2];// we always have two choises take step one or take step two times
        }
        //return sum of all the possibility
        return dp[n];
    }
};
