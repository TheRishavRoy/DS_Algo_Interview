class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int maxLen = 0; // Stores the length of the longest valid subsequence

        //The possible sequence either contains all even elements, all odd elements, alternate even odd, or alternate odd even elements.

        // Try all 4 parity transition patterns:
        // (even→even), (even→odd), (odd→even), (odd→odd)

        //this Nested loop structure will successfully iterate through every possible parity transition.
        for (int firstParity = 0; firstParity <= 1; ++firstParity) 
        {
            for (int secondParity = 0; secondParity <= 1; ++secondParity) 
            {
                int len = 0;          // Current length of valid subsequence
                int prevParity = firstParity; // Parity of previous number
                bool started = false; // Flag to know when to start building the subsequence

                // Traverse through the entire nums array
                for (int num : nums) 
                {
                    int currParity = num % 2; // 0 if even, 1 if odd

                    // Start building subsequence when parity matches the first element of pattern
                    if (!started && currParity == firstParity) 
                    {
                        started = true;
                        len = 1;
                        prevParity = currParity;
                    }
                    // If already started, check if current pair (prev + current) matches target parity
                    else if (started && (prevParity + currParity) % 2 == (firstParity + secondParity) % 2) 
                    {
                        len++;               // Valid transition, so increase subsequence length
                        prevParity = currParity; // Update parity for next comparison
                    }
                }
                // Update the maximum length if this pattern yields longer subsequence
                maxLen = max(maxLen, len);
            }
        }
        return maxLen; // Final result: longest valid subsequence found
    }
};
