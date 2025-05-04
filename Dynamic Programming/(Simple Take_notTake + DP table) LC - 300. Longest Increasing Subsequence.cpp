class Solution {
public:
    int n;
    int t[2501][2501];
    int lis(vector<int>& nums, int prev_idx, int curr_idx) {
       if(curr_idx == n)//if reached end of the array 
           return 0;//simply return recursively
        
        if(prev_idx != -1 && t[prev_idx][curr_idx] != -1)//if not fist element and its value inside memoisation table
            return t[prev_idx][curr_idx];//return memoised value
        
        int taken = 0;
        if(prev_idx == -1 || nums[curr_idx] > nums[prev_idx])//if first element or value of current index more than previous index
            taken = 1 + lis(nums, curr_idx, curr_idx+1);//recursively add 1 to total and call function with: (arr, prev idx, cur idx) for next iteration.
        
        int not_taken = lis(nums, prev_idx, curr_idx+1);//or don't select present index element and continue to next iteration by increasing current index value
        
        if(prev_idx != -1)//if not first element memoize before returning 
            t[prev_idx][curr_idx] =  max(taken, not_taken);
        
        return max(taken, not_taken);//return max of either taking or not taking of present element.
            
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        memset(t, -1, sizeof(t));
        n = nums.size();
        return lis(nums, -1, 0);//array, previous idx, current index
    }
};
