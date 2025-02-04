/*
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
