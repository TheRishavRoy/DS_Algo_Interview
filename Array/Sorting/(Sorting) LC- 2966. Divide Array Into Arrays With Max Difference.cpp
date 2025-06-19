class Solution {
public:
    //step1. First, we sort the array. Then, we take out three elements each time. 
    //step2. If the difference between the maximum and minimum values of these three elements is greater than k,
    //then the condition cannot be satisfied, and we return an empty array. 
    //step3. Otherwise, we add the array composed of these three elements to the answer array.
    vector<vector<int>> divideArray(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());//sort entire array to bunch elements into tightest order together
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; i += 3) //we keep calculating in group of 3
        {
            if (nums[i+2] - nums[i] > k) //check diff of 1st and last element, if either group fails then return void
            {
                /*
                Once the array is sorted, the elements are arranged from smallest to largest. 
                So, any group of three consecutive numbers—say, nums[i], nums[i+1], and nums[i+2]
                will be the most tightly packed possible trio from that segment.If even that minimal spread
                (after sorting) exceeds k, then there's no way those elements could be reshuffled into another
                trio where the max difference would be ≤ k without overlapping other valid groups.
                */
                return {};
            }
            ans.emplace_back(vector<int>{nums[i], nums[i + 1], nums[i + 2]});//else use push_back to answer, emplace does not need extra space. with emplce we need to specify vector<int> before {}
        }
        return ans;
    }
};
