/*
Technique : Using HashMap then Partial Sort
Time Complexity : O(n) average, O(n log n) worst case (due to nth_element)
    - nth_element has average-case O(n) but worst-case O(n log n) depending on pivot selection and input distribution.
    - Still far better than full sorting (O(n log n) every time).

Overall Space Complexity: O(n)
*/


class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> fruitCountDifference;
        int smallestFruitValue = INT_MAX;

        // Count frequency differences and track the smallest fruit value
        for (int& fruit : basket1) {
            fruitCountDifference[fruit]++;
            smallestFruitValue = min(smallestFruitValue, fruit);
        }

        for (int& fruit : basket2) {
            fruitCountDifference[fruit]--;
            smallestFruitValue = min(smallestFruitValue, fruit);
        }

        vector<int> fruitsToSwap;

        // Validate swap feasibility and prepare list of excess fruits
        for (auto& [fruit, difference] : fruitCountDifference) 
        {
            if (difference == 0) 
                continue;

            // If the count difference is odd, it's impossible to balance
            if (difference % 2 != 0) 
                return -1;

            // Push half of the absolute difference to swap list
            // Preparing the list of surplus fruits that need to be exchanged to balance the two baskets.
            // Why Half? : Each swap affects both baskets : -
            // one fruit goes out from one basket and one comes in from the other.
            for (int i = 0; i < abs(difference) / 2; ++i) 
            {
                fruitsToSwap.push_back(fruit);
            }
        }

        // Quick partial sort to get the cheapest half
        // It uses nth_element to make sure you focus on just the cheapest fruits to swap, without sorting the entire list.
        // It places the element at index fruitsToSwap.size() / 2 into its final sorted position.
        // All elements before it are less than or equal to it.
        // So, the first half of the list (from begin() up to that midpoint) will contain the cheapest half of the fruits
        // we only need first half of cheapest elements to swap because swapping effects both ways
        nth_element(
            fruitsToSwap.begin(),
            fruitsToSwap.begin() + fruitsToSwap.size() / 2,
            fruitsToSwap.end()
        );

        // Calculate minimum cost using either direct swap or indirect swap via smallest fruit
        long long totalCost = 0;
        int swapsNeeded = fruitsToSwap.size() / 2;//taking cheapest half of fruitsToSwap
        for (int i = 0; i < swapsNeeded; ++i) 
        {
            // You're looping through the cheapest fruits that need swapping, 
            // And for each one, you're adding to totalCost the minimum of two values
            // 1. fruitsToSwap[i]       : the actual fruit value at index i
            // 2. 2 * smallestFruitValue: the cost of an indirect swap using the cheapest fruit as a bridge
            totalCost += min(fruitsToSwap[i], 2 * smallestFruitValue);
            // Why Multiply by 2?
            // Instead of directly swapping an expensive fruit for another,
            // You swap both fruits through the cheapest fruit available, effectively using it as a middleman
        }
        return totalCost;
    }
};
