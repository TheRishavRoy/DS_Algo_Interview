//using DP (Pre - compute)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1,0);

        /*CONCEPT:
            1. i / 2
                - Integer division by 2 is like shifting right by one bit in binary (i >> 1)
                - This removes the least significant bit (LSB) of i
                - So result[i / 2] gives the number of set bits in i without its last bit
            2. i % 2
                - This gives the value of the last bit of i
                - It's 1 if i is odd, 0 if even
                - So i % 2 tells us whether the dropped bit was a 1
        */
        for(int i=1; i<=n; i++)
        {
            result[i]=result[i/2]/*Integer division by 2 is like shifting right by one bit in binary (i >> 1)*/
                      +i%2;/*This gives the value of the last bit of i*/
        }
        return result;
    }
};
