class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) 
        {
            return 0;
        }
        int left=0,right=0;
        int longestUnique=0;
        unordered_map<char,int> freq;
        while(right<n)
        {
            char cur=s[right];//add from right
            freq[cur]++;//update frequncy in current window

            //freq of each cur has to be == 1, else shrink window from left
            
            while(freq[cur]>1 && left<right)//we have to shrink the window from left
            {
                char leftChar=s[left];
                freq[leftChar]--;//update the frequency in current window since it is going out of the current window
                left++;//move towards right(shrink)
            }
            longestUnique=max(longestUnique,right-left+1);//update max length
            right++;//move right , expand window
        }
        return longestUnique;
    }
};
