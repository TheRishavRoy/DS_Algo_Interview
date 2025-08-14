class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1e9 + 7;

        // dp[j] will store the number of ways to form sum 'j'
        // using powers of unique integers
        vector<int> dp(n + 1, 0);

        // Base case: there's one way to make sum 0 — by choosing nothing
        dp[0] = 1;

        // Try every integer i starting from 1
        for (int i = 1; pow(i, x) <= n; ++i) //staying within limits of n
        {
            // Compute i^x
            int power = pow(i, x);

            // Traverse dp array in reverse to avoid using the same number multiple times
            for (int j = n; j >= power; --j) 
            {
                // Update the number of ways to form sum 'j'
                // by adding the number of ways to form 'j - power'
                dp[j] = (dp[j] + dp[j - power]) % MOD;
            }
        }

        // The answer is the number of ways to form sum 'n'
        return dp[n];
    }
};
