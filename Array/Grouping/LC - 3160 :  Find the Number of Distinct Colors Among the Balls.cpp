class Solution 
{
public:
    std::vector<int> queryResults(int limit, std::vector<std::vector<int>>& queries) 
    {
        unordered_map<int, int> ballToColor;  // [ball] = color
        unordered_map<int, int> colorCount;  // Count occurrences of each color
        vector<int> results;                 // Store results for each query

        for (vector<int>& query : queries) //since original type of queries is vector<int>. We can also write auto& [ball,color] : queries
        {
            int ball = query[0];   // Get the ball number
            int color = query[1];  // Get the color to paint the ball

            if (ballToColor.count(ball)) // If the ball already has a color, we handle it carefully
            {
                int currentColor = ballToColor[ball];//store the ball's current color
                colorCount[currentColor]--; // Decrement the count for the current color

                if (colorCount[currentColor] == 0) //if no balls have this color anymore
                {
                    colorCount.erase(currentColor); // Remove color if no balls have it. otherwise it can cause a problem of storing actual size of colorCount
                }
            }

            ballToColor[ball] = color;   // Paint the ball with the new color
            colorCount[color]++;        // Increment the count for the new color

            results.push_back(colorCount.size()); // Store the number of unique colors
        }

        return results;
    }
};
