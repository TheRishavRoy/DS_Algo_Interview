//=================Approach 1: Sorting=============================
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        
        if(n1!=n2)
            return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        for(int i=0;i<n1; i++)
        {
            if(s[i]!=t[i])
            {
                return false;
            }
        }
        
        return true;
    }
};
//=======================Approach 2: HashMap==================================================================================
//Aproach 2: HashMap
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        std::unordered_map<char, int> charCount;
        for (char ch : s) 
        {
            charCount[ch]++;
        }
        for (char ch : t) 
        {
            charCount[ch]--;
            if (charCount[ch] < 0) 
            {
                return false; // Character in t appears more times than in s
            }
        }
        // If all counts in charCount are 0, they are anagrams
        for (auto &keypair : charCount) 
        {
            if (keypair.second != 0) 
            {
                return false;
            }
        }
        return true;
    }
};
