class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) 
    {
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        vector<int> result;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)//only non zero pushed first
            {    
                result.push_back(nums[i]);
                count++;
            }
        }
        int remaining=n-count;//numbers of element remaing to be pushed(that are zero)
        for(int i=1;i<=remaining;i++)
        {
            result.push_back(0);
        }
        return result;
    }
};
