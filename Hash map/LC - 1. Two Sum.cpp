class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        
        for(int i=0;i<nums.size();i++)
        {
            if(map.find(target-nums[i])!=map.end())//if its pair is found in map just return two indices
            {
                return{map[target-nums[i]],i};
            }
            map[nums[i]]=i;//else keep updating the map anyway <element,index>
        }
        return {};//if nothing found
    }
};
