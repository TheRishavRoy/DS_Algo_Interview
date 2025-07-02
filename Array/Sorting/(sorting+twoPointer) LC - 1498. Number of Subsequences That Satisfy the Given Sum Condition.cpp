/*

1. Sort the array nums : Sorting lets us efficiently find valid min/max pairs using two pointers.

2. Precompute powers of 2 : 2^(right - left) represents the number of subsequences between indices left and right, considering all combinations.

3. Initialize two pointers: left = 0, right = n - 1, and result counter = 0

4. While left <= right:
    If nums[left] + nums[right] <= target:
        - All subsequences formed using nums[left] and any subset of elements between left+1 and right are valid
        - Count them using: 2^(right - left)
        - Add to result, then increment left
    Else:
        - Decrement right to reduce the sum
5. Return result modulo 10^9 + 7

*/
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        // Step 1: Sort the array, so that in any subsequence leftmost is min value and rightmost is max value
        sort(nums.begin(), nums.end());

        // Step 2: Precompute powers of 2 up to n places
        vector<int> power(n, 1);//for n places intialise to 1 and then we go 1,2,4...
        for (int i = 1; i < n; ++i) 
        {
            power[i] = (power[i - 1] * 2) % MOD;
        }

        int left   = 0;
        int right  = n - 1;
        int result = 0;

        while (left <= right) 
        {
            if (nums[left] + nums[right] <= target) 
            {
                //if the current sum of min+max is within target then add 2^length of subsequence to the result
                result = (result + power[right - left]) % MOD;//result+=2^(right - left)
                ++left;//increase minVal to get larger minval+maxval and get closer to target
            } 
            else 
            {
                --right;//else decrease sum by decreasing maxVal
            }
        }
        return result;
    }
};
