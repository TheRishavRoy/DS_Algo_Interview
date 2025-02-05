class Solution {
public:
    bool areAlmostEqual(string str1, string str2) {
        // Initialize a counter to track the number of positions where str1 and str2 differ
        int differenceCount = 0;
        // Variables to store the characters from each string when a mismatch is found
        char charFromStr1 ,charFromStr2;
      
        // Iterate through both strings to compare character by character
        for (int index = 0; index < str1.size(); ++index) {
            char charA = str1[index], charB = str2[index];
          
            // If there is a mismatch, we'll need to check further
            if (charA != charB) {
                // Increment the difference counter and check if it exceeds 2. If it does, return false as more than one swap won't make them equal
                if (++differenceCount > 2 || (differenceCount == 2 && (charA != charFromStr2 || charB != charFromStr1)))//also if difference is 2 we need to compare from last time when we got unequal characters.current charA should be equal to previous charB and vice versa only then we can swap thwm. 
                {
                    return false;
                }
                // Update the characters that were found to mismatch for comparison when the next mismatch occurs
                charFromStr1 = charA, charFromStr2 = charB;
            }
        }
        // If there was exactly one mismatch, strings cannot be made equal with a single swap
        // Return true if difference count is 0 or 2 (since they can be equal after exactly one swap); otherwise, return false
        return differenceCount != 1;
    }
};
