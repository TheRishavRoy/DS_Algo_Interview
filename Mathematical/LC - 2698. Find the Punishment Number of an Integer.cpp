class Solution {
public:
    // Function to calculate the sum of special numbers
    int punishmentNumber(int n) 
    {
        int sum = 0; // Initialize sum of the special numbers
        // Loop through all numbers from 1 to n
        for (int currentNum = 1; currentNum <= n; ++currentNum) 
        {
            int square = currentNum * currentNum; // Calculate the square of the current number
            string squareStr = std::to_string(square); // Convert the square to a string
            // Check if the square satisfies the condition
            if (isSpecialNumber(squareStr, 0, currentNum)) 
            {
                sum += square; // Add the square to the sum if the condition is satisfied
            }
        }
        return sum; // Return the sum of special numbers
    }

    // Helper function to check if the given string represents a special number
    bool isSpecialNumber(const string& numStr, int index, int num) 
    {
        int strSize = numStr.size(); // Size of the number string
        // If we've reached beyond the end of the string, check if num is 0 (completely decomposed)
        if (index >= strSize) 
        {
            return num == 0;//The problem is trying to determine whether a number's square can be split into parts such that their sum equals the number itself. If at the end of the string, the remaining value of num is 0, it confirms that the decomposition is successful.
        }
        int partialSum = 0; // Initialize the partial sum of digits from 'index'
        // Iterate through the string starting from 'index'
        for (int j = index; j < strSize; ++j) 
        {
            partialSum = partialSum * 10 + numStr[j] - '0'; // Build the number by appending the digit
            // If the partial sum exceeds the remaining value of num, break (no further checks needed)
            if (partialSum > num) 
            {
                break;
            }
            // Recurse to check if the remaining part of the string can make up the number num - partialSum
            if (isSpecialNumber(numStr, j + 1, num - partialSum)) 
            {
                return true; // If the condition holds, return true
            }
        }
        // If no valid decomposition found, return false
        return false;
    }
};
