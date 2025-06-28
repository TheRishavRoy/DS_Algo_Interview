class Solution {
public:
    bool canFormPairs(vector<int>& nums, int maxDiff, int p) 
    {
        int count = 0;
        
        // Iterate through the sorted array
        for (int i = 1; i < nums.size(); i++) {
            // If the difference between consecutive elements is within the allowed maxDiff
            if (nums[i] - nums[i - 1] <= maxDiff) {
                count++;  // Pair is formed
                i++; // Skip the next element since it is already paired
            }
            if(count >= p)//early return if we hv met the criteria
                    return true;
        }
        
        return count >= p; // Check if at least p pairs were formed
    }

    int minimizeMax(vector<int>& nums, int p) 
    {
        // Sorting the array to ensure consecutive pairing is optimal
        sort(nums.begin(), nums.end());

        int left = 0; // Minimum possible difference
        int right = nums.back() - nums.front(); // Maximum possible difference
        int result = right; // Store final answer

        // Binary search for the smallest possible max difference
        while (left <= right) 
        {
            int mid = left + (right - left) / 2; // Midpoint for binary search
            
            // Check if we can form at least p pairs within this difference
            if (canFormPairs(nums, mid, p)) 
            {
                result = mid; // Update result to a potentially smaller valid max difference
                right = mid - 1; // Search for an even smaller difference
            } 
            else 
            {
                left = mid + 1; // Increase difference threshold
            }
        }

        return result; // Return the minimized maximum difference
    }
};
