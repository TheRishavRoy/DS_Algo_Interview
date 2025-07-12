class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        // Step 1: Compute all gaps (free time between meetings)
        vector<int> gaps;
        gaps.push_back(startTime[0]); // Before first meeting
        for (int i = 1; i < n; ++i) 
        {
            gaps.push_back(startTime[i] - endTime[i - 1]); // Between meetings
        }
        gaps.push_back(eventTime - endTime[n - 1]); // After last meeting

        // Step 2: Precompute max gaps to the left and right of each meeting
        vector<int> maxLeft(n + 1);
        vector<int> maxRight(n + 1);
        maxLeft[0] = gaps[0];
        for (int i = 1; i <= n; ++i)
            maxLeft[i] = max(maxLeft[i - 1], gaps[i]);//max gap seen so far coming from left

        maxRight[n] = gaps[n];
        for (int i = n - 1; i >= 0; --i)
            maxRight[i] = max(maxRight[i + 1], gaps[i]);//max gap seen so far cominf from right

        // Step 3: Try rescheduling each meeting and compute max free time
        int maxFree = 0;
        for (int i = 0; i < n; ++i) 
        {
            int duration = endTime[i] - startTime[i];
            int adjacentGaps = gaps[i] + gaps[i + 1];//These are the two gaps surrounding the current meeting. If it's removed or moved, they can be merged.

            //now, You're checking whether there’s a gap either before the current location or further ahead that’s large enough to hold this meeting:
            bool canMove = false;
            if (i > 0/*no seg fault*/ && maxLeft[i - 1] >= duration) //if moved left meeting will end up at slot i-1
                canMove = true;
            if (i + 2 <= n && maxRight[i + 2] >= duration)//if moved right meeting will end up at i+2
                canMove = true;

            int totalFree = adjacentGaps + (canMove ? duration : 0);
                maxFree = max(maxFree, totalFree);
        }

        return maxFree;
    }
};
