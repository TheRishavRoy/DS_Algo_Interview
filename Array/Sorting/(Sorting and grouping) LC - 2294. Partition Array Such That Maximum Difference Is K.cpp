class Solution {
public:
    int partitionArray(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());//sort to easily track max and min and difference max-min of a subsequence
        int n=nums.size();

        int start=0;//pick a start index of first subsequence        
        int subSequences=1;//intially only 1 subsequence is there

        for(int end=0; end<n ; ++end)//we keep moving end towards right, expanding the subsequence
        {
            if(nums[end]-nums[start]>k)//if value exceds k we need to start a new subsequence
            {
                ++subSequences;//increment number of subsequences
                start=end;//pick the start of this new subsequence
            }
        }
        return subSequences;
    }
};
