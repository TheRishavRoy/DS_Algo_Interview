class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1); // Initialize all with one candy

        // Left to right pass (ensuring increasing rating gets more candies)
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) 
            {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right to left pass (ensuring decreasing rating gets more candies)
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) 
            {
                //already candies[i] could be greater because of the first paas
                //so check with max function
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Sum all candies to get final result
        int result = 0;
        for (int candy : candies) {
            result += candy;
        }

        return result;
    }
};
