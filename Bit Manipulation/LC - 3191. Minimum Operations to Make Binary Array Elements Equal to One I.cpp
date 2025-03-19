/*
DESCRIPTION:

You are given a binary array nums.

You can do the following operation on the array any number of times (possibly zero):

Choose any 3 consecutive elements from the array and flip all of them.
Flipping an element means changing its value from 0 to 1, and from 1 to 0.

Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, return -1.
=========================================================================================================================

TC: O(N)
SC: O(1)

*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operations = 0;

        for (int i = 0; i <= n - 3; i++) 
        {
            if (nums[i] == 0) 
            {
                // Flip the next 3 elements
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                operations++;
            }
            //if nums[i]!=0 no need to do anything
        }

        // If the last two elements are not 1, it's impossible
        //because we can't flip any further
        for (int i = n - 2; i <= n-1 ; i++) 
        {
            if (nums[i] == 0) return -1;
        }

        return operations;
    }
};
