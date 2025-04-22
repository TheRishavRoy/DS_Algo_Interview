/*LC - Hard, key is understanding adjacent pair property and using main and max heap */
/*Efficient solution with O(n+klogn) complexity*/
/*
    -We can only insert k−1 cuts between elements, meaning we should focus on adjacent pairs.
    -Each cut affects the first and last elements of a partition, so our goal is to:
    -Find the smallest possible sum (minimize first and last elements).(min heap)
     Find the largest possible sum (maximize first and last elements).(max heap)
*/
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) 
    {
        int n = weights.size();
        vector<int> pairSum;

        // Step 1: Compute pair sums
        //we store pair sum because eventually we will make k-1 cut
        //and score is decided based on 1st and last element of that cut
        //so in the end we will find the cut that gives k-1th largest sum and k-1th smallest sum after storing and sorthing them by a heap(min and max)
        for (int i = 0; i < n - 1; i++) 
        {
            pairSum.push_back(weights[i] + weights[i + 1]);
        }
        
        /* NOTE:
        We only use adjacent pairs beacuse we want to minimize and maximize weights[i] + weights[i+1]
        This is only possible if we take adjacent pairs
        Therefore using heap we pick k-1 cuts out of n-1 cut.*/
        
        
        //We focus on the sum of adjacent pairs in the array (weights[i] + weights[i+1]) because splitting into k parts means we pick k-1 splits.
        // Step 2: Use heaps to find min & max `k-1` sums
        priority_queue<int> maxHeap(pairSum.begin(), pairSum.end()); // Max heap
        priority_queue<int, vector<int>, greater<int>> minHeap(pairSum.begin(), pairSum.end()); // Min heap

        long long maxSum = 0, minSum = 0;
        
        // Step 3: Extract the top (k-1) elements
        for (int i = 0; i < k - 1; i++) {
            maxSum += maxHeap.top(); maxHeap.pop();
            minSum += minHeap.top(); minHeap.pop();
        }

        return maxSum - minSum; // Difference of max & min sums
    }
};
