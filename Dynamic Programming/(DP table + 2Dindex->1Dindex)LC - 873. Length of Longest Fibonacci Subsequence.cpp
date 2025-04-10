/*
Thinking of recursion + backtracking for subsequence problems is natural, but for this problem, it can be tricky due to the Fibonacci condition
arr[i]+arr[j]==arr[k]

Simply trying to include or exclude elements (like typical subsequence problems) doesn't leverage the Fibonacci condition.
Too big time complexity

Optinmal:
=========
- Fix two elements (A[i], A[j]) as the starting two elements.
- Use HashSet / HashMap to quickly check if A[i] + A[j] exists in the array.
- If it exists, keep extending the sequence.
*/

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) 
    {
        int n = arr.size();
        //to find target arr[k] we use:
        unordered_map<int, int> index; // Value -> Index map

        //to keep track of length
        //represents the length of Fibonacci-like subsequence ending at (i, j).
        unordered_map<int, int> dp;    // (j, i) -> Length
        
        // Step 1: Store index of each element in the map
        for (int i = 0; i < n; i++) 
        {
            index[arr[i]] = i;
        }
        
        int maxLen = 0;

        // Step 2: Try every pair (arr[j], arr[k]) to start the Fibonacci sequence
        for (int j = 0; j < n; ++j) 
        {
            for (int k = j + 1; k < n; ++k) 
            {
                int target = arr[k] - arr[j];//target is arr[i], stored in map in line 17
                if (target < arr[j] && index.count(target)) //to ensure that in Fibonacci-like sequence, the numbers are strictly increasing (arr[i]<arr[j]) AND target actually exist and 
                {
                    int i = index[target];//find index of the target element
                    //we have to maps the 2D index (i, j) to a 1D index
                    //dp[i∗n+j]≡dp[i][j]
                    int length = dp[i * n + j] + 1;//If the longest subsequence till arr[i] and arr[j] is dp[i][j], then including arr[k] will increase the length by 1.
                    dp[j * n + k] = length;//updating length in dp table till arr[k]
                    maxLen = max(maxLen, length);//update max len
                }
                else 
                {
                    dp[j * n + k] = 2; // Start of a new sequence. So length at the start of seq is 2 arr[i] & arr[j]
                }
            }
        }
        
        return maxLen>2 ? maxLen : 0;
    }
};
