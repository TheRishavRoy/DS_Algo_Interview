/*The Problem statement should be rephrased as:

Traverse the stirng for left to right
Whenever we see a * we remove the * and remove first non-* character to  left
*/

class Solution {
public:
    string clearStars(string s) 
    {
        stack<int> charStack[26];     // Use 26 stacks for each lowercase alphabet character.
        int n = s.length();           // Length of the input string.
        vector<bool> toRemove(n);     // Vector to indicate which characters to remove.

        // Traverse the string and process each character.
        for (int i = 0; i < n; ++i) 
        {
            if (s[i] == '*') 
            {             
                // If the current character is '*', mark for removal.
                toRemove[i] = true;
                // Find the first non-empty stack and remove the character index from it.
                for (int j = 0; j < 26; ++j) 
                {
                    if (!charStack[j].empty()) 
                    {
                        toRemove[charStack[j].top()] = true; // Mark the character at the top of the stack for removal.
                        charStack[j].pop(); // Remove the index from the stack.
                        break;
                    }
                }
            } 
            else 
            {
                charStack[s[i] - 'a'].push(i); // Push the index of the character into the respective stack.
            }
        }

        string result;
        // Build the result string with characters that are not marked for removal.
        for (int i = 0; i < n; ++i) 
        {
            if (!toRemove[i]) 
            {
                result.push_back(s[i]);
            }
        }
        return result; // Return the final processed string.
    }
};
