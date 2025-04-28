class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count = 0;
        long long currentSum = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            currentSum += nums[right];
            // Shrink the window if the score is greater than or equal to k
            while (left <= right && currentSum >= k / (right - left + 1.0/*1.0 handles floating number*/)) // same as : currentSum*(right - left + 1)>=k
            {
                currentSum -= nums[left];//subtract nums[i] getting out of window to reduce product
                left++;//shrink from left
            }
            // All subarrays ending at 'right' with a starting point >= 'left'
            // will have a score less than k
            count += (right - left + 1);//number of valid subarrays are : right-left+1
        }
        return count;
    }
};
