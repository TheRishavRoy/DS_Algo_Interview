class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // Step 1: Copy and sort to find the top k values
        vector<int> copy = nums;
        sort(copy.begin(), copy.end(), greater<int>());//copy array in descending order so that top k elements are starting from index 0

        // Step 2: Count occurrences of top k values (handles duplicates), we need to keep duplicates also
        unordered_map<int, int> freq;
        for (int i = 0; i < k; ++i) 
        {
            freq[copy[i]]++;
        }

        // Step 3: Iterate through original array and collect in-order top k values
        vector<int> result;
        for (int num : nums) 
        {
            if (freq[num] > 0) //it will be there only if it is in top k values
            {
                result.push_back(num);
                freq[num]--;//reduce its frequence
            }
        }
        return result;
    }
};
