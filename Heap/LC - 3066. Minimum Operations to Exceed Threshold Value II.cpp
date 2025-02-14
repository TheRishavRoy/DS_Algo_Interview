class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        int ans = 0;
        priority_queue<long, vector<long>, greater<>> minHeap;

        // Push all elements of nums into the minHeap
        for (const int num : nums)
            minHeap.push(num);

        // While we don't run out of numbers smaller than k
        while (minHeap.size() > 1 && minHeap.top() < k) 
        {
            const long x = minHeap.top(); // Pick the smallest element
            minHeap.pop();

            const long y = minHeap.top(); // Pick the second smallest element
            minHeap.pop();

            // Push back as described in the question
            minHeap.push(min(x, y) * 2L + max(x, y));
            ans++; // Increment the number of operations
        }

        // If the heap still contains elements smaller than k, we cannot satisfy the condition
        if (!minHeap.empty() && minHeap.top() < k)
            return -1;

        return ans;
    }
};
