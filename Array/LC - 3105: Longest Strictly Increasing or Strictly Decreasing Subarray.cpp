/*
Approach 1: (Iterative)
T.C.: O(N) . N= size of array
*/
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        int n = nums.size();
        int maxLen = 1;
        int incLen = 1;
        int decLen = 1;

        for (int i = 1; i < n; ++i) 
        {
            if (nums[i] > nums[i - 1]) 
            {
                incLen++;
                decLen = 1;//reset decLen
            } 
            else if (nums[i] < nums[i - 1]) 
            {
                decLen++;
                incLen = 1;//reset incLen
            } 
            else 
            {
                incLen = 1;//reset both
                decLen = 1;
            }
            maxLen = max(maxLen, max(incLen, decLen));//update max
        }
        return maxLen;
    }
};
/*
Approach 2: (Recursive)
The idea here is to start from array idx=0  and initialize maxLen=1
Now we parse fron idx=1 to idx=n-1 using recursion with ahelper function, and keep updating the incLen and decLen, while keeping track of maxLen found so far.
We reset the counters whenever strictly inc or dec is violated.

T.C.: O(N) . N= size of array

The recursive function processes each element exactly once and moves to the next index in a straightforward manner. 
Since there are no overlapping subproblems or branching recursions (like divide-and-conquer), the time complexity is:

*/
class Solution {
public:
    int longestSubarrayHelper(vector<int>& nums, int idx, int incLen, int decLen, int& maxLen)
    {
        if (idx == nums.size()) 
            return maxLen; // Base case: end of array
        
        if(nums[idx]>nums[idx-1])
        {
            incLen++;
            decLen=1;//reset
        }
        else if(nums[idx]<nums[idx-1])
        {
            decLen++;
            incLen=1;//reset
        }
        else//cound be nums[i]==nums[i-1]. which neither strictly inc or dec
        {
            decLen=1;//reset
            incLen=1;//reset
        }
        maxLen = max(maxLen, max(incLen, decLen)); // Update max length
        return longestSubarrayHelper(nums, idx + 1, incLen, decLen, maxLen);//keep increasing the index till we hit base condition
    }
    int longestMonotonicSubarray(vector<int>& nums) 
    {
        if(nums.empty())
            return 0;
        
        int maxLen = 1;
        return longestSubarrayHelper(nums, 1, 1, 1, maxLen);//array,idx,incLen,decLen,maxLen
    }
};
