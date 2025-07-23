class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        unordered_set<int> seen;
        int left = 0, score = 0, maxScore = 0;

        for (int right = 0; right < nums.size(); ++right) 
        {
            while (seen.count(nums[right])) //whenever we get a repeating number to right
            {
                seen.erase(nums[left]);//we first remove all its occurence from left
                score -= nums[left];//remove score as well
                ++left;//move th window towards right
            }
            seen.insert(nums[right]);//now update the seen with right's value
            score += nums[right];//update the score
            maxScore = max(maxScore, score);//compare with MaxScore
        }
        return maxScore;
    }
};
