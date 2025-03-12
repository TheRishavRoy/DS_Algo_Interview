class Solution {
public:
    int numberOfSubstrings(string s) {
        // Initialize an array to store the last seen positions of 'a', 'b', and 'c'.
        int lastSeenPositions[3] = {-1, -1, -1};
      
        // Initialize the answer to 0.
        int substringCount = 0;
      
        // Iterate over the string.
        for (int index = 0; index < s.size(); ++index) 
        {
            // Update the last seen position for the current character.
            lastSeenPositions[s[index] - 'a'] = index;
          
            // Find the smallest index among the last seen positions of 'a', 'b', and 'c'.
            // Add 1 because indices are 0-based, and we're interested in the number of elements.
            int minLastSeenPosition = min(lastSeenPositions[0], 
                                          min(lastSeenPositions[1], lastSeenPositions[2])) + 1;
            /*
            This works because:
            initially: -1 is the minLastSeen index for all three
            if min=-1 means one of them not seen, so total added to result = -1+1 = 0
            But, if minLastSeen index is anything>-1 means we can get a valid answer.

            If idx is the minLastSeen idx then till this point, we have got atleast one occurence of all three character a,b,c.
            */
            
          
            // Add the number of valid substrings ending with the current character.
            // This is possible because any substring ending at the current index
            // and starting before or at the smallestLastSeen index will contain all three characters.
            substringCount += minLastSeenPosition;
        }
      
        // Return the total count of valid substrings.
        return substringCount;
    }
};
