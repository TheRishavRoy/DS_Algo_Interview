/*
==================================================================================================================
STEP 1: |
========
1. Each query [l, r] decrements elements in range [l, r]. Instead of updating every element one by one, we use 
   Differnce Array:
   
    diff[l]--       → Decrease nums[l] by 1.
    diff[r + 1]++   → Restore balance after index r.
    
2. This ensures that the impact spreads correctly when processing nums.


===================================================================================================================
STEP 2: |
========
1. Delta keeps track of how much should be added/subtracted at index i.
2. Keep adding nums[i] += delta;

3. Apply the accumulated changes to nums[i].
   Instead of modifying nums[i] for each query, we apply all modifications in one pass.
===================================================================================================================
*/
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> diff(n+1,0);//one more so that we can always update r+1

        // Apply range updates using the difference array
        for(auto &query:queries)
        {
            int l=query[0];
            int r=query[1];
            --diff[l];//   Decrement at start of range
            if(r+1<n)
                ++diff[r+1];// Restore balance after range
        }
         // Apply difference array to transform `nums`
        int delta=0;
        for(int i=0; i<n ; ++i)
        {
            delta += diff[i];  // Accumulate changes
            nums[i]+=delta;
        }

        for(int &num:nums)
        {
            if(num>0)//don't check !=0  since negative number is fine since sometime we may modify 0 to -1. which is fine according to our answer either 0 or -ve is okay
                return false;
        }
        return true;
    }
};
