class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        // If total is odd, can't split into two equal parts
        if (total % 2 != 0) //can never be divided 
            return false;
        
        int target = total / 2;
        int n = nums.size();
        
        //dp[i] is true if a "subset sum of i" is possible using any of the subset of the given array
        vector<bool> dp(target + 1, false);//Initialised to false
        dp[0] = true;//sum 0 is always possible with an empty subset

        for (int num : nums) //For every number num, update the dp array in reverse (to avoid using the same number multiple times).
        {
            for (int j = target; j >= num; --j) 
            {
                //To determine if a subset with sum j is possible
                //A subset with sum j was already possible (dp[j] is true)
                // OR : A subset with sum j - num was possible before, and now we add num to reach j.
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
};
