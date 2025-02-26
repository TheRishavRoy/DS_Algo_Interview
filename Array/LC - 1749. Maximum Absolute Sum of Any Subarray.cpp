//using kadane's algorithm:
TC: O(N)
SC: O(1)
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_sum = 0, min_sum = 0, curr_max = 0, curr_min = 0;
        //The key idea is the max absolute sum will be either the max sum or the min sum.
        //So just run kadane twice, once calculating the max sum and once calculating the min sum.
        for (int num : nums) {
            curr_max = max(num, curr_max + num);
            max_sum = max(max_sum, curr_max);

            curr_min = min(num, curr_min + num);
            min_sum = min(min_sum, curr_min);
        }

        return max(abs(max_sum), abs(min_sum));
    }
};
