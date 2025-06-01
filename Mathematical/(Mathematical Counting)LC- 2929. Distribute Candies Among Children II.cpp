class Solution 
{
public:
    long long distributeCandies(int n, int limit) 
    {
        long long ways = 0;

        // Iterate over possible candy counts for the first child

        /*1.If the first child gets too many candies, there might not be enough left for the second and third child.
            Second and third child can each receive at most limit candies, 
            So we ensure that at least 2 * limit candies remain after assigning candies to the first child.
            This will ensure a minimum value goto child1*/
        int minCh1 = max(0, n - 2 * limit); //minimum candies to child1 while keeping within limit for each child

        /*2. Maximum to child 1 will be eaither limit or if n is samaller than limit */
        int maxCh1 = min(n, limit);         // Maximum candies for child 1 (bounded by limit)

        for (int i = minCh1; i <= maxCh1; i++) 
        { // Fix the candies for child 1, loop through possibities of first child
            
            int remainingCandies = n - i; // Candies left for child 2 and child 3

            // Determine valid range for child 2's candies
            int minCh2 = max(0, remainingCandies - limit); // Minimum candies for child 2 by reserving  limit candies for giving it later to 3rd child
            int maxCh2 = min(remainingCandies, limit);     // Maximum candies for child 2 is either limit or whatever is left after giving to the first child

            // The number of ways child 2 can take candies affects child 3 automatically
            ways += maxCh2 - minCh2 + 1; // Count all valid distributions
        }
        return ways;
    }
};
