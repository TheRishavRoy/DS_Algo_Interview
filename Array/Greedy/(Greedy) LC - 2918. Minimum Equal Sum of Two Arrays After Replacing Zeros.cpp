class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2)
    {
        long long sum1 = 0;
        long long sum2 = 0;
        int numZero1 = 0;
        int numZero2 = 0;

        for (int num : nums1) {
            sum1 += num;
            if (num == 0) {
                ++numZero1;
            }
        }

        for (int num : nums2) {
            sum2 += num;
            if (num == 0) {
                ++numZero2;
            }
        }

        long long minSum1 = sum1 + numZero1;//this much we have to add to first sum to get rid off all zeros
        //this is because:
        //we have to replace numZero1 number of Zeros with atleast value of 1
        long long minSum2 = sum2 + numZero2;
        //same goes for min sum that will be required for second sum

        if (numZero1 == 0 && sum1 < minSum2) //if there is no Zero left in 1st array, but its sum1 is less than minSum2 of Array2 
        {
            return -1;//we don't have any zero left to convert so that we can get to minSum2
        }
        if (numZero2 == 0 && sum2 < minSum1) {
            return -1;
        }

        return max(minSum1, minSum2);
    }
};
