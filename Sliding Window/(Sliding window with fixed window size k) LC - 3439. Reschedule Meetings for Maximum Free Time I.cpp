class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps(n + 1);

        // 1. Gap before the first meeting
        gaps[0] = startTime[0];

        // 2. Gaps between meetings
        for (int i = 1; i < n; ++i) 
        {
            gaps[i] = startTime[i] - endTime[i - 1];
        }

        // 3. Gap after the last meeting
        gaps[n] = eventTime - endTime[n - 1];

        // 4. Find maximum sum of (k+1) consecutive gaps
        int maxSum = 0, windowSum = 0;
        /*classic sliding window implementation for computing the maximum sum of k + 1 consecutive elements in the gaps array—nicely applied here for finding the longest possible free time after shifting up to k meetings.*/

        for (int i = 0; i <= n; ++i) 
        {
            windowSum += gaps[i];//Add the current gap to the sliding window. 
            
            //There is never a need to rest windowSum because, 
            //If the window is now larger than k + 1, you subtract the oldest value (gaps[i - k - 1]) to keep the window fixed.

            if (i > k) //If the window size exceeds k + 1
            {
                windowSum -= gaps[i - k - 1];//remove the gap that's falling out of the window (gaps[i - k - 1]).
                //since window size is fixed
            }

            if (i >= k) //Once the window is big enough , from now on i>=k so we keep comapring  max(maxSum, windowSum)
            {
                maxSum = max(maxSum, windowSum);//check if the current windowSum is the largest you've seen.
            }
        }

        return maxSum;
    }
};
