class Solution {
public:
    int minCapability(vector<int>& nums, int k) 
    {
        int left = 0;//min
        int right = *max_element(nums.begin(), nums.end());//max
        int result = right; // Initialize result to the maximum possible value
        
        while (left < right) //Use < when minimizing (to stop as soon as left == right is found)
        {
            int mid = (left + right) >> 1;//int mid = (left + right) / 2;
            if (isCapable(nums, k, mid)) 
            {
                right = mid; // Try to find a smaller valid capability
                //we have to return minimum capability
            } 
            else 
            {
                left = mid + 1; // Increase capability requirement
            }
        }
        //In this approach, the while loop continues as long as left < right. 
        //When the loop terminates, 
        //left will be equal to right, and this value represents the minimum capability found.
        return left;
    }

private:
    bool isCapable(const vector<int>& nums, int k, int capability) 
    {
        int count = 0;
        int prevIndex = -2;
        for (int i = 0; i < nums.size(); ++i) 
        {
            if (nums[i] > capability || i == prevIndex + 1) 
            {
                //cannot rob if nums[i] > capability
                //or if houses are adjacent 
                continue;
            }
            ++count;// Increment the count of houses robbed
            if(count >= k)
                return true;//early return
            prevIndex = i;// Update the index of the last robbed house
        }
        return count >= k;
    }
};
