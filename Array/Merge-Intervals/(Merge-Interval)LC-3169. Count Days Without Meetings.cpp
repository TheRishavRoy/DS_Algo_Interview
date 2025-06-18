/*
Using Sorting + Merge Intervals

Instead of using an array of size days, store only meeting intervals and merge overlapping ones to count free days.
=============================================================================
Steps
1. Sort the meetings by start time.
2. Merge overlapping intervals to track occupied days.
3. Subtract occupied days from total days.
============================================================================
Sapace:
We only store and process n meetings, not days
Memory usage is O(n) instead of O(days).

Time:
Sorting + Merging is Efficient
Sorting takes O(n log n).
Merging takes O(n).
Overall complexity: O(n log n) (much better than O(n × d)).
*/
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) 
    {
        // Sort meetings based on start time
        sort(meetings.begin(), meetings.end());

        int occupiedDays = 0;
        int prevStart = -1, prevEnd = -1;

        // Merge overlapping intervals
        for (auto &meeting : meetings) 
        {
            int start = meeting[0], end = meeting[1];

            if (start > prevEnd) {
                // Non-overlapping meeting, add previous interval's length
                if (prevStart != -1) //if not the first interval
                    occupiedDays += (prevEnd - prevStart + 1);

                // Update new interval
                prevStart = start;
                prevEnd = end;
            } 
            else {
                // Overlapping meeting, extend the current interval
                prevEnd = max(prevEnd, end);
            }
        }

        // Add the last of the merged interval
        //since we are adding range later after checking for overlap
        //the last interval gets missed in the loop
        if (prevStart != -1) 
            occupiedDays += (prevEnd - prevStart + 1);

        // Compute free days
        return days - occupiedDays;
    }
};
