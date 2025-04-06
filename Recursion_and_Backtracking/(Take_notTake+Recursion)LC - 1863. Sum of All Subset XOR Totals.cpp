//In this we explore the concept of take+not take
//We use recursion to form a current_subset by take/not take nums[i]
//base case: once we reach end of nums: idx==nums.size, We push current_subset to a List of All_subsets
//at last we sum up XOR of all subsets


//Approach-1 (Using simple backtracking to generate subsets)
//T.C : O(n * 2^n)
//S.C : O(n * 2^n)
class Solution {
public:

    void solve(vector<int>& nums, int i, vector<int>& currSubset, vector<vector<int>>& subsets) 
    {

        if (i == nums.size()) //if we have reached nums.size then all elements 0...n-1 is parsed
        {
            subsets.push_back(currSubset);//push current subset to set of all subsets
            return;//return void
        }

        currSubset.push_back(nums[i]);//take element i
        solve(nums, i + 1, currSubset, subsets);//then explore currSubset possibilities
        currSubset.pop_back();//and next time I don't take it
        solve(nums, i + 1, currSubset, subsets);//and again explore

        //so we now have one currSubset with nums[i] and another without nums[i]
        
    }

    int subsetXORSum(vector<int>& nums) 
    {
        vector<vector<int>> subsets;//all subsets
        vector<int> currSubset;//current subset
        solve(nums, 0, currSubset, subsets);//call to calculate recursive subsets

        int result = 0;
        for (auto& currSubset : subsets) //iterate over all subsets
        {
            int Xor = 0;
            for (int num : currSubset) //for all elements in current subset
            {
                Xor ^= num;//calculate xor of this subset
            }
            result += Xor;//add it to xor of all subsets
        }
        return result;
    }
};
