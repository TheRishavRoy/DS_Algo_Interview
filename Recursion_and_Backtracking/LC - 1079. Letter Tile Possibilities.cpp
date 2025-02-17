class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0); // Frequency array for letters A-Z

        //key concept: The frequency array ensures that duplicate characters (like the two 'A's in "AAB") are not treated as separate choices at the same recursion level.

        // Count the frequency of each character in the string
        for (char c : tiles) {
            freq[c - 'A']++;
        }

        // Perform backtracking and return the total count
        int count=backtrack(freq);
        return count;
    }

    int backtrack(vector<int>& freq) {
        int count = 0; // Number of valid sequences generated

        // Loop through each character in the frequency array
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) // If this character is still available
            { 
                freq[i]--;     // Use the character
                count++;       // Count the current sequence

                count += backtrack(freq); // Explore further sequences after taking this character

                freq[i]++;     // Backtrack (restore the character)
            }
        }

        return count;
    }
};
