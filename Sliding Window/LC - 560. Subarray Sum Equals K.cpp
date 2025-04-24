//This aproach will work for non-negative nums only
//to handle neagtive numbers use prefixSum + HashMap

int subarraySumNonNegative(vector<int>& nums, int k) {
    int n = nums.size();
    int start = 0, end = 0;
    int sum = 0, count = 0;

    while (end < n) {
        sum += nums[end];//expand from right, update sum

        while (sum > k && start <= end) //if sum exceds k then shrink from left index
        {
            sum -= nums[start];//reduce sum
            ++start;//shrink
        }

        if (sum == k) //founf one ans
        {
            ++count;
        }

        ++end;//expand from right
    }

    return count;
}
