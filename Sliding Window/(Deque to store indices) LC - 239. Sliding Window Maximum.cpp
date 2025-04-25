class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        deque<int> dq;
        vector<int> result;
        int n=nums.size();

        //The front of the deque always holds the index of the maximum element in the current window.
        //As the window slides, we:
        // - Remove out-of-bound indices.
        // - Remove all indices with smaller elements since they won't be needed.
        for(int i=0 ; i<n ; ++i)
        {
            while(!dq.empty() && dq.front()<=i-k)//i-k is the start of the window
            {
                //anything outside the start of the window i.e. i-k should be removed
                dq.pop_front();
            }
            //while the nums[index_in_dq] of indices at the back of dq is < nums[i]
            //we remove those indices first before inserting index i of nums[i]
            while(!dq.empty() && nums[dq.back()]<nums[i])
            {
                dq.pop_back();
            }
            //now we can push indices i into deque since now nums[i]>=nums[dq.back()]
            dq.push_back(i);
            // // Start adding to result only when first window is complete
            if(i>=k-1)//index is 0 based thats why >=k-1 not >k-1
            {
                result.push_back(nums[dq.front()]);
                //dq.front holds the index of largest element in the current window
            }
        }
        return result;
    }
};
