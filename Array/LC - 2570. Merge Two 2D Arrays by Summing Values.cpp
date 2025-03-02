class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            unordered_map<int,int> value_of_id;
            for(int i=0 ; i<nums1.size() ; i++)
            {
                int id=nums1[i][0];
                int value=nums1[i][1];

                value_of_id[id]+=value;
            }
            for(int i=0 ; i<nums2.size() ; i++)
            {
                int id=nums2[i][0];
                int value=nums2[i][1];

                value_of_id[id]+=value;
            }
            vector<vector<int>> result;
            
            for(auto &it:value_of_id)
            {
                result.push_back({it.first,it.second});//values need to be pushed as a pair
            }

            sort(result.begin(), result.end());
            return result;
        }
    };
