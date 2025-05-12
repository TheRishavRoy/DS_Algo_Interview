class Solution {
private:
    set<int> uniqueEvenNumbers;
    vector<int> currentPermutation;
    vector<bool> used;
    vector<int> originalDigits;

    void generatePermutations(int length) 
    {
            
        if (currentPermutation.size() == length) //we check length sepeately because if length==3 we return regardless of what happens in inner if check
        {
            if(currentPermutation[0] != 0 && currentPermutation[2] % 2 == 0)
                uniqueEvenNumbers.insert(currentPermutation[0] * 100 + currentPermutation[1] * 10 + currentPermutation[2]);
            
            return;//we return when length is 3 thats why this has to be outside if check above
        }

        for (int i = 0; i < originalDigits.size(); ++i) 
        {
            if (!used[i]) 
            {
                //DO
                used[i] = true;
                currentPermutation.push_back(originalDigits[i]);
                //EXPLORE
                generatePermutations(length);
                //UNDO
                currentPermutation.pop_back();
                used[i] = false;
            }
        }
    }

public:
    vector<int> findEvenNumbers(vector<int>& digits) 
    {
        originalDigits = digits;
        int n = digits.size();
        used.resize(n, false);
        generatePermutations(3);

        vector<int> result(uniqueEvenNumbers.begin(), uniqueEvenNumbers.end());
        return result;
    }
};
