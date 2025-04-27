class Solution {
public:
    bool check(string &s, int i, int j){//checking if substring is palindrome
        while(i<j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }            
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0;
        int maxLen=0;
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)//since lower-half of truth matrix is useless.Since startpoint cannot be more than ending.
            {
                  if(check(s, i, j))//pass substring with start and end point
                  {
                        if(j-i+1 > maxLen)//if new maxLen is greatter update maxLen
                        {
                            maxLen = j-i+1;//update endpoint of largest palindrome
                            start = i;//update start point of largest palindrome
                        }
                  }                 
            }
        }
        return s.substr(start, maxLen);
    }
};
