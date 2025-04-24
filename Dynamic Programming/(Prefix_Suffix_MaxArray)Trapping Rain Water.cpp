class Solution {
public:
    //Prefix/Suffix Max Array Method
    //Also DP because we pre-compute and reuse previus results
    int trap(vector<int>& height) {
        int n = height.size();
        int result = 0;

        vector<int> left(n), right(n);

        left[0] = height[0];
        right[n - 1] = height[n - 1];

        for (int i = 1; i < n; i++) 
        {
            //left[i]: tallest bar from the start to index i.
            left[i] = max(left[i - 1], height[i]);
        }

        for (int i = n - 2; i >= 0; i--) 
        {
            //right[i]: tallest bar from the end to index i.
            right[i] = max(right[i + 1], height[i]);
        }

        for (int i = 0; i < n; i++) 
        {
            //water taht can be trapped at index i:
            //min(left[i], right[i]) - height[i]
            result += min(left[i], right[i]) - height[i];
        }

        return result;
    }
};
