/*
Approach : Min heap
Complexity : O(N log N) time (Sorting the events takes O(N log N), and each heap operation (insert/remove) also takes log N, performed up to N times.)
             O(N) space (The min-heap stores at most N events simultaneously, leading to O(N) space in the worst case.)

Here’s how the strategy deals with overlapping events step by step:

Step 1: Sort events by start day This ensures you're evaluating events in chronological order and not missing any earlier opportunities.

Step 2: Use a min-heap to store end days When multiple events are available on the same day, the heap helps prioritize:
            - Events with earlier end days go to the top
            - These are the most urgent to attend—if you skip them today, you may lose the chance
Step 3: On each day (d):
            - Add to heap: All events that start on or before d (i.e., available now)
            - Remove from heap: Any event whose end day is before today (minHeap.top() < d). These have expired—can't attend them
Step 4: Attend one event:
            - Pick the one with the soonest end day (minHeap.pop())
            - Attend it, count it, move to the next day

Continue until all events have been processed and heap is empty
*/





class Solution {
public:
    int maxEvents(vector<vector<int>>& events) 
    {
        int ans = 0;  // Total events attended
        int d = 0;    // Current day
        int i = 0;    // Index for iterating over events
        priority_queue<int, vector<int>, greater<>> minHeap; // Min-heap to store end days of available events

        // Sort events by their start day to process chronologically
        sort(events.begin(), events.end());

        // Continue until all events have been processed and heap is empty
        while (!minHeap.empty() || i < events.size()) 
        {
            // If no event is available to attend today, jump to the next event's start day
            if (minHeap.empty())
                d = events[i][0];

            // Add all events that start today or earlier to the heap (they're available now)
            while (i < events.size() && events[i][0] <= d)
                minHeap.push(events[i++][1]); // Push event's end day

            // Remove events that have already ended (can't be attended)
            while (!minHeap.empty() && minHeap.top() < d)
                minHeap.pop();

            // If there's any event left to attend, pick the one that ends earliest
            if (!minHeap.empty()) {
                minHeap.pop(); // Attend this event
                ++ans;         // Count it as attended
                ++d;           // Move to next day
            }
        }

        return ans; // Return the total number of events attended
    }
};
