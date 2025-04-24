class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // This handles the edge case when the subarray itself from the beginning sums up to k.

        int prefixsum = 0, resultCount = 0;

        for (int num : nums) 
        {
            prefixsum += num;
            // if prefixsum-k exist there exists a sum == k also exists
            //For each new prefix sum prefixsum, you check if prefixsum - k exists in the map.
            //If it does, that means there's a subarray ending at the current index that sums to k.
            if (prefixSumCount.find(prefixsum - k) != prefixSumCount.end()) 
            {
                resultCount += prefixSumCount[prefixsum - k];
            }

            prefixSumCount[prefixsum]++;//You use a hash map prefixSumCount to store how many times each prefix sum has occurred.
        }

        return resultCount;
    }
};
