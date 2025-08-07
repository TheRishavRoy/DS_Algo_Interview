class Solution {
public:
    // Returns the maximum number of fruits that can be collected within k steps from startPos
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) 
    {
        int n = fruits.size();
        int maxFruits = 0; // Track the maximum fruits collected
        int left = 0;      // Left pointer of the sliding window
        int sum = 0;       // Sum of fruits in the current window

        // Iterate over each fruit position using the right pointer
        for (int right = 0; right < n; ++right) 
        {
            // Add fruits at the current right position to the sum
            sum += fruits[right][1];

            // Shrink the window from the left if the steps exceed k
            while (left <= right) 
            {
                // Distance from startPos to the leftmost and rightmost fruit in the window
                int distLeft = abs(startPos - fruits[left][0]);
                int distRight = abs(startPos - fruits[right][0]);

                // Total distance between left and right fruit positions
                int totalDist = fruits[right][0] - fruits[left][0];

                // Minimum steps needed to collect fruits from left to right
                // Either go to the leftmost first, then to the rightmost, or vice versa
                //Go to the closer end first (min(distLeft, distRight))
                //Then walk across the entire range (totalDist = fruits[right][0] - fruits[left][0])
                int minSteps = min(distLeft, distRight) + totalDist;

                // If within allowed steps, keep the window
                if (minSteps <= k) 
                    break;

                // Otherwise, remove the leftmost fruit and move the window forward
                sum -= fruits[left][1];
                ++left;
            }

            // Update the maximum fruits collected
            maxFruits = max(maxFruits, sum);
        }

        return maxFruits;
    }
};
