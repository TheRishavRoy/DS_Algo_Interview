/*
Why getDigitSum is private ?
======================================================================================================================================
1.Encapsulation:
The helper function getDigitSum is an implementation detail of the Solution class.
By marking it as private, you're signaling that this function should only be used internally by the class and not be accessible from outside.
---------------------------------------------------------------------------------------------------------------------------------------
2.Avoid Accidental Access:
If the helper function is not part of the public interface of the class, it shouldn't be exposed.
Making it private prevents users of the class from calling it directly, reducing the risk of misuse.

HOW to access a private function outside the class:
-A private function can be called by a public or protected function within the same class. 
External code can invoke the public function, which in turn calls the private function.
- OR by using a Friend function
==========================================================================================================================================
*/
class Solution {
private:
    int getDigitSum(int num) 
    {
        int sum = 0;
        while (num > 0) 
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> digitSumMap; // Stores {the sum of digits },{the max number seen so far with this sum}
        int maxPairSum = -1;//final ans

        for (int num : nums) 
        {
            int digitSum = getDigitSum(num);

            // If this sum already exists, calculate the sum of the pair and update maxPairSum
            if (digitSumMap.find(digitSum) != digitSumMap.end()) 
            {
                maxPairSum = max(maxPairSum, digitSumMap[digitSum] + num);//updated
            }

            // Update the map to store the maximum number seen so far for this digit sum as well
            //there can be more than two number with equal digitSum, we might use this number again
            digitSumMap[digitSum] = max(digitSumMap[digitSum], num);        
        }
        return maxPairSum;
    }
};
