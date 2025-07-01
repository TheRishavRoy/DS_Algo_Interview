class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int count = 1; // No-mistake case

        for (int i = 0; i < n;) 
        {
            int j = i + 1;//start just after i
            while (j < n && word[j] == word[i]) //while consecutive letters are same, there can be mistake(s) 
            {
                j++;
            }

            int len = j - i;//length of streak
            if (len > 1) 
            {
                count += len - 1;//1 less because orginal string does not contribute to possibilities
            }

            i = j; // move to the next group(next set of repeating characters), update i for next iteration
        }
        return count;
    }
};
