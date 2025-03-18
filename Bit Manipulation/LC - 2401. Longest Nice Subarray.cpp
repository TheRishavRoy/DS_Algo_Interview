class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, niceLength = 0;
        int bitmask = 0; // Tracks OR of current window

        //use sliding window and two pointers left,right:
        for (int right = 0; right < n; ++right) {
            // If nums[right] conflicts with the existing bitmask
            while ((bitmask & nums[right]) != 0 )//We should check if any bit in bitmask and nums[right] overlaps (i.e., bitmask & nums[right] != 0).
            {
                //If bitmask has a bit set that was contributed by nums[left], XOR removes it.
                bitmask ^= nums[left]; // Remove left element from OR
                left++; // Shrink window
            }

            /*
            The OR operation (|) sets bits in bitmask according to nums[right].
            It helps track which bits are "occupied" in the current window.
            */
            
            // Add nums[right] to OR mask
            bitmask |= nums[right];

            // Every subarray ending at 'right' is valid, therefore update max length of nice subarrays
            niceLength = max(niceLength,(right - left + 1));
        }

        return niceLength;
    }
};
