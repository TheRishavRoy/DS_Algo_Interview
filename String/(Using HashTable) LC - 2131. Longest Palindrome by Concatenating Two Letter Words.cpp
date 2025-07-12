class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        unordered_map<string, int> mp;

        int result = 0;

        for(string &word : words) 
        {
            string reversedWord = word;//for each Original word, form a reversed word
            swap(reversedWord[0], reversedWord[1]);//forming reverse word. Since word_len==2(for each word in words) we can easily swap 

            if(mp[reversedWord] > 0)//if freq of reverseWord of word is > 0 
            {
                result += 4;//we can increase length of palindrom by 4 since word+reverseWord = 4
                mp[reversedWord]--;//decrease freq of reverseWord since it is already used
            } 
            else 
            {
                mp[word]++;//else we push word to be later used as reverseWord
            }
        }
        //Check equal character words. Use only one of these words.(in the centre
        for(auto &it : mp) 
        {
            string word = it.first;
            int count = it.second;

            if(word[0] == word[1] && count > 0) 
            {
                result += 2;//using it once(at the centre) increases length by 2
                break;
            }
        }
        return result;
    }
};
