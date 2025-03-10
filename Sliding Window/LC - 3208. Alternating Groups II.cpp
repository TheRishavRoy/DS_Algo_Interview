class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) 
        {
            int n = colors.size();  // Get the size of the input vector
            int result = 0;            // Initialize a counter for number of alternating groups
            int count = 0;            // Initialize a counter for the current group length
    
            //Iterate through the array twice
            //This effectively considers two rounds of the original circle, 
            //Allowing handling of wraparound in a straightforward manner.
            for (int i = 0; i < n * 2; i++) 
            {
                // Check if current color is the same as the previous one
                if (i > 0 && colors[i % n] == colors[(i - 1) % n]) 
                {
                    count = 1;  // Resets count if consecutive colors are the same
                } 
                else 
                {
                    ++count;  // Else Increment current group length
                }
              
                // If we've completed one loop and the group is at least of length k
                if (i >= n && count >= k) //to deal with wrap around case we are waiting till we reach i==n
                {
                    ++result;  // Increase the alternating groups count
                }
            }
          
            return result;  // Return the total number of alternating groups            
        }
    };
