/*
Description:

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
*/
class Solution
{
public:
    bool isIsomorphic(string s, string t) {
      //since in constraints it is already mentioned s and t lengths are equal, we are not checking for equal length to return false in case of unequality
      
      vector <int> charToIndex_s(128);//ascii characters are 127
      vector <int> charToIndex_t(128);//for a given character if not already saved, previous index is zero
      //thats why we start from index =1

      for(int i=0; i<s.size();i++)
      {
            if (charToIndex_s[s[i]] != charToIndex_t[t[i]])//if at any point mapping for two strings are different, by comparing previus occurence
                return false;
        
            charToIndex_s[s[i]] = i + 1;//we use index to map the characters
            charToIndex_t[t[i]] = i + 1;//keep updating current index of both character in two strings
      }
      return true;
    }
};
