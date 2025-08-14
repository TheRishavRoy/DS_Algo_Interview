class Solution {
public:
    unordered_map<int, unordered_map<int, double>> memo;
    /*
    MAP       : memo
    The key   : is an int (representing a)
    The value : is another unordered_map<int, double> (mapping b to the result of dp(a, b))
    */

    double dp(int a, int b) 
    {
        // Step 1 : All base cases
        // 1.0 Base case: both soups A and B are empty at the same time : Return 0.5 as per problem definition
        if (a <= 0 && b <= 0) 
            return 0.5;

        // 1.1 Base case: soup A is empty but soup B is not : A finishes first, Return 1.0
        if (a <= 0) 
            return 1.0;

        // 1.2 Base case: soup B is empty but soup A is not : B finishes first, Return 0.0
        if (b <= 0) 
            return 0.0;

        // =====================================================================================================
        // Step 2 : If this state (a, b) has already been computed, return the memoized result
        if (memo[a].count(b)) 
            return memo[a][b];

        // ===========================================================================================================
        // Step 3 : Compute the probability for current state (a, b) by averaging the four possible serving operations
        // Think of it like rolling a 4-sided die. pour 100 : a-4 ; pour 75 : a-3 ....and so on

        memo[a][b] = 0.25 * (    // Probability of any one operation being chosen is: 0.25
            dp(a - 4, b) +       // Serve 100ml of A, 0ml of B
            dp(a - 3, b - 1) +   // Serve 75ml of A, 25ml of B
            dp(a - 2, b - 2) +   // Serve 50ml of A, 50ml of B
            dp(a - 1, b - 3)     // Serve 25ml of A, 75ml of B
        );

        // Return the computed probability for state (a, b)
        return memo[a][b];
    }

    double soupServings(int N) 
    {
        if (N >= 4800) //at large value of N the probability closes to 1.0 you can say around 5000
            return 1.0;
        int n = ceil(N / 25.0);//Since all serving operations are multiples of 25 ml, you normalize N to units of 25.
        //You reduce the number of possible states
        //faster computation in Memoization

        return dp(n, n);
    }
};
