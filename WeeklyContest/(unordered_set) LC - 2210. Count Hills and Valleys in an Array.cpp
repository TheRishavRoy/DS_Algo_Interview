class Solution {
public:
    int countHillValley(vector<int>& nums) 
    {
        vector<int> filtered;
        
        // Remove consecutive duplicates
        for (int num : nums) 
        {
            if (filtered.empty() || filtered.back() != num) {
                filtered.push_back(num);
            }
        }

        //now start actual check and counting
        int count = 0;
        for (int i = 1; i < filtered.size() - 1; ++i) //first and lst index cannot be hill/vally
        {
            if ((filtered[i] > filtered[i - 1] && filtered[i] > filtered[i + 1]) /*Hill*/
                 || (filtered[i] < filtered[i - 1] && filtered[i] < filtered[i + 1]))/*Valley*/
            {
                ++count;
            }       
        }
        return count;
    }
};
