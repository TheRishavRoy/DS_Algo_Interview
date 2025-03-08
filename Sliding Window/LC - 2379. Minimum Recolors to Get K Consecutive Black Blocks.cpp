/*
Approach : Sliding window
Start from window i=0 to i=k-1 (k elements)
slide the window from right starting at idx i=k all the way to i=n-1

TC: O(N)
*/
class Solution {
public:
    int minimumRecolors(string blocks, int k) 
    {
        int n = blocks.size();
        if(k>n)
            return -1;//invalid case

        int whiteCount = 0;

        // Count 'W' in the first window of size k
        for (int i = 0; i < k; i++) 
        {
            if (blocks[i] == 'W') 
                whiteCount++;
        }

        int minOperations = whiteCount; // Initial min operations

        // Slide the window across the string
        for (int i = k; i < n; i++)//we start from idx i=k i.e. start of 2nd window 
        {
            // Remove the first element of the previous window
            if (blocks[i - k] == 'W')//if first eement of previous window was white 
                whiteCount--;//we have reduced wcount by removing a white block
            // Add the new element in the window
            if (blocks[i] == 'W') 
                whiteCount++;

            // Update minOperations
            minOperations = min(minOperations, whiteCount);
        }

        return minOperations;
    }
};
