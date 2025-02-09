class Solution {
public:
    long long countBadPairs(vector<int>& nums) 
    {
        //total number of pair= nC2
        int n=nums.size();
        // easier to count the number of pairs that are not bad pairs
        long long totalPairs = (long long)n * (n - 1) / 2;//use long long in intermidiate calculation also to avoid overflow

         // Bad pairs = Total pairs - Good pairs

        unordered_map <int,int> mp;//key=good_pair,val=freq of that goodpair

        long long goodPairs=0;

        for(int i=0 ; i<n ; i++)
        {
            int val=nums[i];
            int key=val-i;
            if(mp.count(key)!=0)
            {
                goodPairs+=mp[key];// Add the frequency of the key to goodPairs
            }
            mp[key]++; 
        }
        return totalPairs - goodPairs; // Bad pairs = Total pairs - Good pairs
    }
};
