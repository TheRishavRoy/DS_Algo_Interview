/*
Approach 1: Recursive
same approach as in LC 3105
T.C. : O(N) N is number of eleemnts in vector
*/
class Solution 
{
public:
    int helperSum(int idx, vector<int>& nums,int ascSum, int maxSum)
    {
        if(idx==nums.size())//if we reached till the end
            return maxSum;//return final anser
        if(nums[idx]>nums[idx-1])
        {
            ascSum+=nums[idx];//update sum
        }
        else
        {
            ascSum=nums[idx];//reset sum
        }
        maxSum=max(maxSum,ascSum);
        return helperSum(idx+1, nums, ascSum, maxSum);
    }
    int maxAscendingSum(vector<int>& nums) 
    {
        int ascSum=nums[0];//initialize our sum with value of first element in array. we start our subarray from here
        int maxSum=nums[0];//we keep updating maxSum
        return helperSum(1, nums, ascSum, maxSum);//we keep parsing nums starting from nums[1]
    }
};

/*===========================================*
Approach 2: Kadane's algorithm (Iterative):
Use curSum and maxSum
*============================================*/
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) 
    {
        if (nums.empty()) 
        {
            return 0;
        }
        
        int maxSum = nums[0];
        int currentSum = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) 
        {
            if (nums[i] > nums[i - 1]) 
            {
                currentSum += nums[i];
            } 
            else 
            {
                currentSum = nums[i];
            }
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};
