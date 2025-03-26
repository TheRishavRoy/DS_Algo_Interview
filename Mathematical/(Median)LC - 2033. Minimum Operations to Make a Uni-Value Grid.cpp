class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) 
    {
        vector<int> nums;
        for(auto &row:grid)
        {
            for(auto num:row)//since we are not modifying num only reading and storing &num is not necessary 
            {
                nums.push_back(num);
            }
        } //we want to flaten the grid

        //sort to get median
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];//taking median of all the elements
        //we use median as targetr for all elements 
        
        int ops = 0;

        for (int num : nums) 
        {
            int diff = abs(num - median);
            if (diff % x != 0) //we cannot use x to reach median
                return -1;  // If not divisible by x, return -1
            ops += diff / x;
        }
        
        return ops;
    }
};
