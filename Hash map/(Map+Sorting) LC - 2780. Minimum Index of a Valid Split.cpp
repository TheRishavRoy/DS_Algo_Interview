class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> frequency;

        // Count frequency of each element
        for (int num : nums) {
            frequency[num]++;
        }

        // Find dominant element (element with max frequency)
        int dominant = -1, maxFreq = 0;
        for (auto& [num, freq] : frequency) {
            if (freq > maxFreq) {
                dominant = num;
                maxFreq = freq;
            }
        }

        int leftCount = 0, rightCount = maxFreq;

        // Try to find the minimum valid split index
        for (int i = 0; i < n - 1; i++) // stopping at n-1, this ensures we leave one element in right partitioning
        {  
            if (nums[i] == dominant) 
            {
                leftCount++;//Tracks how many times the dominant element appears in the left partition (nums[0] to nums[i]).
                rightCount--;//Tracks how many times the dominant element appears in the right partition (nums[i+1] to nums[n-1]).
            }

            // Check if dominant in both partitions
            //(i + 1) is the size of the left partition.
            //(n - (i + 1)) is the size of the right partition.
            if (leftCount * 2 > (i + 1) && rightCount * 2 > (n - (i + 1))) 
            {
                return i;
            }
        }

        return -1; // No valid split found
    }
};
