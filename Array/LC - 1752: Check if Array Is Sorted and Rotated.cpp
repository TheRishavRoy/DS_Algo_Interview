class Solution {
public:
    /*
    The array can be considered non-decreasing if there's at most one
    "out-of-order" pair which could be the point of rotation.
    */
    bool check(vector<int>& nums) 
    {
        // Initialize the count of "out-of-order" pairs to 0.
        int outOfOrderCount = 0;

        // Get the size of the array.
        int n = nums.size();

        // Loop through the array elements.
        for (int i = 0; i < n; i++) 
        {
            // Increase the "out-of-order" count if the current element is greater than the next element. 
            //We use modulo operation to compare the last element with the first element.
            if (nums[i] > nums[(i + 1) % n]) 
            {
                outOfOrderCount++;
            }
        }
        // The array can be considered non-decreasing if there's at most one
        // "out-of-order" pair which could be the point of rotation.
        return outOfOrderCount <= 1;
    }
};
