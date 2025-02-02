class Solution 
{
public:
    bool isArraySpecial(vector<int>& nums) 
    {
        int n=nums.size();
        if(n<2)//no need to check
        {
            return true;
        }
        if(n==2)//corner case
        {
            if((nums[0]%2==0 && nums[1]%2==0) || (nums[0]%2!=0 && nums[1]%2!=0))
                return false;
        }
        for(int i=1; i<n-1; i++)
        {
            if(nums[i]%2==0)//even number
            {
                if(nums[i-1]%2==0 || nums[i+1]%2==0)//neighbours should not be even
                {
                    return false;
                }
            }
            else//odd case
            {
                if(nums[i-1]%2!=0 || nums[i+1]%2!=0)//should not be also odd 
                {
                    return false;
                }
            }
        }
        return true;    
    }
};
