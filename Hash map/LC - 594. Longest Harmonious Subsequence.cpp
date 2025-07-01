class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        int longest = 0;

        // Count frequencies
        for (int num : nums) {
            ++freq[num];
        }

        //suseq need not be contiguous 
        //they can occur at any place
        // Check pairs with difference = 1
        for (auto& [num, count] : freq) 
        {
            if (freq.count(num + 1)) //since num and num+1 will have diff == 1
            {
                longest = max(longest, count + freq[num + 1]);//add freq of num+(num+1) and comapre with longest so far
            }
        }

        return longest;
    }
};
