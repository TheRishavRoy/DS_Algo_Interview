class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) //once for each bit in a 32-bit number.
        {
            //Step 1:
            result <<= 1;//Makes room for the next bit by shifting everything in result to the left.
            //The least significant bit (LSB) becomes empty, ready to receive a new value.
            
            //Step 2:
            result |= (n & 1);
            //n & 1 isolates the last bit of n (1 if odd, 0 if even).
            //|= adds that bit to the rightmost position of result.

            //Step 3:
            n >>= 1;//Removes the last bit from n, bringing the next bit into position for the next iteration. (Step 1 and Step 2)
        }
        return result;
    }

};
