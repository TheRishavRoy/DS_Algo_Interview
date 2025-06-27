//Greedy+Bitwise operation
//T.C : O(n)
//S.C : O(1)
class Solution 
{
public:
    int longestSubsequence(string s, int k) 
    {
        int length = 0; // Length of valid subsequence
        long long powerValue = 1;  // 2^position intially 2^0=1
        
        // Traverse from right to left from LSB to MSB
        for (int i = s.size() - 1; i >= 0; --i) 
        {
            if (s[i] == '0') //Always include '0's—they’re free.
            {
                length++;//incfrease subsequence length
            } 
            else if(powerValue <= k) //Including a '1' increases the binary value
            {
                //Including a '1' increases the binary value
                length++;//increase length but take care of k as well
                k -= powerValue;
            }

            //increase powerValue for next iteration, i.e. moving towards MSB
            if (powerValue <= k)//if its safe, i.e. staying within boundary of k
                powerValue <<= 1; //powerValue *= 2;
        }        
        return length;
    }
};
