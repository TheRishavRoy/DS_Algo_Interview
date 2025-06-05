class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();
        if (numFriends == 1)//If only one friend plays, return the full word. No splitting needed.
            return word;

        set<string> collection;

        //Since at least one character must be assigned to each friend, we reserve (numFriends - 1) characters.
        //The remaining length (n - (numFriends - 1)) represents the largest substring we can take in a given step.
        int longestPossible = n - (numFriends - 1);

        for (int i = 0; i < n; i++) 
        {
            //Ensure we don’t exceed available characters(n-i) while still taking the longest valid substring.
            int canTakeLength = min(longestPossible, n - i);
            //put substring into the set
            collection.insert(word.substr(i, canTakeLength));
        }

        return *collection.rbegin(); // Ensures lexicographic max without duplicates
    }
};
