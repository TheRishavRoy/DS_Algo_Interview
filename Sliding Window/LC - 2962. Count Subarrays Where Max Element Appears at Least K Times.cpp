class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // Find the maximum value in the array
        int maxVal = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        long long answer = 0; // This will store the final count of subarrays
        int countMax = 0; // Counts the number of maximum elements in the current subarray
        int j = 0; // Pointer to extend the right boundary of the subarray

        // Iterate through the array, considering each element as the start of a subarray
        for (int i = 0; i < n; ++i) {
            // Extend the subarray until we either run out of elements
            // or we have 'k' instances of the maximum element
            while (j < n && countMax < k) {
                countMax += nums[j] == maxVal;
                ++j;
            }
            // If we have less than 'k' instances, we cannot form more subarrays
            // starting from the current element
            if (countMax < k) break;

            // Add the number of possible subarrays that start with the current element
            answer += n - j + 1;

            // Prepare for the next iteration by decrementing the count if the current
            // element is the maximum value
            countMax -= nums[i] == maxVal;
        }

        // Return the total count of qualifying subarrays
        return answer;
    }
};
