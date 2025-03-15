class Solution {
public:
    long long countOfSubstrings(string word, int k) 
    {
        return substringsWithAtMost(word, k) - substringsWithAtMost(word, k - 1);//returns the count of substrings with EXACTLY "k" consonants. == atMost(k)-atMost(k-1)
    }

private:
    long substringsWithAtMost(const string& word, int k) 
    {
        if (k < 0) 
            return 0;

        long res = 0;
        int vowels = 0, consonants = 0;
        unordered_map<char, int> vowelLastSeen;
        unordered_map<char, int> vowelFreq;

        int l = 0;
        //use sliding window to see if in the present window we have 
        for (int r = 0; r < word.length(); r++) 
        {
            if (isVowel(word[r])) 
            {
                if (++vowelFreq[word[r]] == 1)
                    ++vowels; // Unique vowel count increases
                vowelLastSeen[word[r]] = r;
            } 
            else 
            {
                ++consonants;
            }

            // Shrink window if consonants exceed k
            while (consonants > k) 
            {
                if (isVowel(word[l])) 
                {
                    if (--vowelFreq[word[l]] == 0)
                    --vowels; // Unique vowel count decreases
                } 
                else 
                {
                    --consonants;
                }
                ++l;
            }

            if (vowels == 5) 
            { 
                // Check if all vowels are present
                int minVowelIndex = min({vowelLastSeen['a'], vowelLastSeen['e'],
                                 vowelLastSeen['i'], vowelLastSeen['o'],
                                 vowelLastSeen['u']});//the min value will give the smallest index where all vowels a,e,i.. hv been seen already
                res += minVowelIndex - l + 1;//number of valid substrings ending at r
                //minVowelIndex - l gives number of indices bw l and minVowelIndex
                //but we want including index l therefore +1
            }
        }
        return res;
    }

    bool isVowel(char c) 
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
