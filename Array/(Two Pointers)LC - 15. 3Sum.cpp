class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        sort(nums.begin(),nums.end());
        
        int len=nums.size();
        
        for(int i=0;i<len;i++)
        {
            int j=i+1;
            int k=len-1;
            
            while(j<len && j<k)
            {
                if(nums[j]+nums[k]==-nums[i])
                {
                    result.push_back({nums[i],nums[j],nums[k]});
                    while(k!=0 && nums[k]==nums[k-1])
                        k--;
                    while(j!=len-1 && nums[j]==nums[j+1])
                        j++;
                    
                    
                    j++;
                    k--;
                }
                else if(nums[j]+nums[k]>-nums[i])
                {
                    while(k!=0 && nums[k]==nums[k-1])
                        k--;
                    
                    k--;
                }
                else if(nums[j]+nums[k]<-nums[i])
                {
                    while(j!=len-1 && nums[j]==nums[j+1])
                        j++;
                    
                    j++;                    
                }
                while(i!=len-1 && nums[i]==nums[i+1])
                    i++;                      
                
            }
            
        }
        return result;
    }
};
