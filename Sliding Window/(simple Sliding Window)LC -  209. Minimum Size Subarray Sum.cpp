class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums)
    {
        int windowSum = 0;
        int left = 0, right = 0;
        int minSize = INT_MAX;
        int n = nums.size();
        while (right < n)
        {
            windowSum += nums[right];
            if (windowSum >= target)
            {
                minSize = min(minSize, right - left + 1);
            }
            while (windowSum >= target && left <= right)
            {
                minSize = min(minSize, right - left + 1);
                windowSum -= nums[left];
                left++;
            }
            right++;
        }
        return (minSize == INT_MAX) ? 0 : minSize;
    }
};
