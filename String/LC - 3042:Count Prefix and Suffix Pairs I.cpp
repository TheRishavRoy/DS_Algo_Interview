class Solution {
public:
    
    bool isPrefixAndSuffix(string &check, string &str) {
        int n = check.length();

        //You can use fine() function as well
        //Extracts a prefix (s1) and suffix (s2) of length check.length() from s.
        string sub1 = str.substr(0, n);//starting at 0
        string sub2 = str.substr(str.length() - n, n);//starting point of this substring will be n before last
        
        return sub1 == check && sub2 == check;//return true if both are equal to check
        
    }
    
    int countPrefixSuffixPairs(vector<string>& words) {
        /*
        auto lambda = [](string& s1, string& s2) 
        {
            return s1.length() < s2.length();
        };
        
        sort(begin(words), end(words), lambda);
        */
        
        int count = 0;
        for(int i = 0; i < words.size()-1; i++) //we go till 1 less than last , because anyway j starts at i+1
        {
            for(int j = i+1; j < words.size(); j++) 
            {
                /*
                Both  word[i] lenth has to be less than or equal to word[j]
                and isPrefix has to meet*/
                if(words[i].length() <= words[j].length() && isPrefixAndSuffix(words[i], words[j])) 
                {
                    count++;
                }
            }
        }
        
        return count;
    }
};
