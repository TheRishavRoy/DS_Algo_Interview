class Solution {
public:
    bool canDistribute(vector<int>& candies, long long k, int mid) 
    {
        long long childrenCount = 0; // Number of children we can satisfy

        for (int candy : candies) //Loops through candies[] and counts how many children can be satisfied
        {
            childrenCount += (candy / mid); // How many children can be satisfied from this pile  by giving "mid" candies to each child.
            //NOTE: since we cannot give one child candie from more than one pile. we don't sum up candies[i]
            //INSTEAD: For each pile we get candy/mid childrenCount and the sum it to childrenCount and check if it satisfies : childrenCount >= k
            
            if (childrenCount >= k) //if k children can be satiesfied this could be our answer (~return early since we already got answer)
                return true; // so return true, we can distribute among >=k children
        }
        return childrenCount >= k;//(~return anyway)
    }

    int maximumCandies(vector<int>& candies, long long k) 
    {
        int left = 1;
        int right = *max_element(candies.begin(), candies.end());
        int result = 0;

        //we use binary search to determine the maximum number of candies that can be given to each child.
        //The minimum possible allocation is 1
        //The maximum possible allocation is max(candies[]), because no child can get more than the largest pile.
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            //Check if it's possible to give each child "mid" candies by counting how many children can be satisfied.
            if (canDistribute(candies, k, mid)) 
            {
                result = mid;  // Store the valid allocation
                left = mid + 1; // Try for a larger mid
            } 
            else 
            {
                right = mid - 1; // Try for a smaller mid
            }
        }
        return result;
    }
};
