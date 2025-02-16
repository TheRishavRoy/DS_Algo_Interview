//TC: O(targetLength×wordLength)
/*
SC: 
O(targetLength×wordLength) for the DP table.
O(wordLength×26) for the character count array.
O(targetLength) for the recursion stack.
*/
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int MOD = 1e9 + 7; // Define the modulus to keep the numbers within the integer limit
        //(const to keep it unmodified)
        int targetLength = target.size();
        int wordLength = words[0].size(); // Size of the target string and length of each word in the array
        
        vector<vector<int>> count(wordLength, vector<int>(26)); 
        // 2D vector to store the count of each character at each position
        //since all word is of equal length
        //we store freq of each character a,b..c at count[0],count[1]....each index
      
        // Loop to count the frequency of each character at each column in the word list
        for (auto& word : words) 
        {
            for (int j = 0; j < wordLength; j++) 
            {
                ++count[j][word[j] - 'a']; // Increment the count of the character at the relevant position
                //increasing the count of character "(word[j]-'a')" at index "j"
            }
        }

        // Use a dynamic DP array with std::vector
        vector<vector<int>> dp(targetLength, vector<int>(wordLength, -1));
        //e.g. : if target ="abc" then dp[2][3] means Number of ways to form the substring "c" (starting from target[2]) using columns 3 onward.

        // Call the helper DFS function
        return dfs(0, 0, targetLength, wordLength, count, target, dp, MOD);
    }

private:
    int dfs(int i, int j, int targetLength, int wordLength, const vector<vector<int>>& count, const string& target, vector<vector<int>>& dp, int MOD) {
        if (i >= targetLength) {
            return 1; // If the whole target is found, return 1 way
        }
        if (j >= wordLength) {
            return 0; // If the end of the word is reached, no more ways can be found, return 0
        }
        if (dp[i][j] != -1) {
            return dp[i][j]; // If the value is already computed, return the cached result
        }
        int ways = dfs(i, j + 1, targetLength, wordLength, count, target, dp, MOD); 
        // Recursive call to check for ways without using the current position
        
        // Add the ways using the current character and proceed
        ways = (ways + 1LL * dfs(i + 1, j + 1, targetLength, wordLength, count, target, dp, MOD) * count[j][target[i]-'a']) % MOD; 
        
        return dp[i][j] = ways; // Store the computed ways in the DP array for memoization
    }
};
