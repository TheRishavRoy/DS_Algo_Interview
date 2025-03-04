/*
The number can not be represented as a sum of powers of 3 if it's ternary presentation has a 2 in it

In base-3, digits can be 0, 1, or 2. If a number can be represented as a sum of distinct powers of 3, 
that means: (𝑎0*3^0) + (𝑎1*3^1) + (𝑎2*3^2 )+ …
where each 𝑎𝑖 ​ is either 0 or 1.

If the number can be represented in power of 3, this ternary equation should only have 0 or 1
e.g.: 7 in ternary is 21 → (2 * 3^1) + (1 * 3^0) = 6 + 1 = 7 (Hence, CANNOT be Represented)


Time Complexity: O(log₃(n))
*/

class Solution {
public:
    
    bool checkPowersOfThree(int n) {
        //The number can not be represented as a sum of powers of 3 if it's ternary presentation has a 2 in it
        //7 in ternary is 21 → (2 * 3^1) + (1 * 3^0) = 6 + 1 = 7         
        //since 2 is there 7 cannot be represented in power of 3

        while (n > 0) 
        {
            int rem = n % 3; // Get the last digit in Base 3 . Since this sum of power of 3 we consider base 3.
            if (rem == 2) 
            {
                return false; // If any digit is 2, return false
            }
            n /= 3; // Remove the last digit
        }
        return true; // If no 2 is found, return true
    }
};
