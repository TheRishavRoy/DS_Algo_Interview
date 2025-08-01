/*
Description:
============
Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.

The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. 
*/
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;  // Stores all unique bitwise OR results across subarrays
        unordered_set<int> curr;    // Stores OR results of subarrays ending at the previous element

        // Iterate through each element in the array
        for (int num : arr) {
            unordered_set<int> next;  // Will store ORs of subarrays ending at current element
            next.insert(num);         // Single-element subarray: [num]

            // Extend previous subarrays by appending current number
            for (int val : curr) {
                next.insert(val | num);  // Compute OR with current number and add to next
            }

            curr = next;  // Update curr to reflect subarrays ending at current element
            result.insert(curr.begin(), curr.end());  // Add current ORs to the global result
        }

        return result.size();  // Return the count of distinct OR results
    }
};
