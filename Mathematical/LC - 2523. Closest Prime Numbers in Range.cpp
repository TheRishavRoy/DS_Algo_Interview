class Solution {
public:
    vector<int> closestPrimes(int left, int right) 
    {
        vector<int> primes;

        for(int i=left ; i<=right ; i++)
        {
            if(isPrime(i))
                primes.push_back(i);
        }
        if (primes.size() < 2) 
            return {-1, -1}; // Not enough primes 

        //initialise result vector with{-1,-1}
        vector<int> result(2,-1);

        int minDiff=INT_MAX;
        // Compare adjacent primes
        for (int i = 1; i < primes.size(); i++) 
        {
            if (primes[i] - primes[i - 1] < minDiff) 
            {
                minDiff = primes[i] - primes[i - 1];
                result[0] = primes[i - 1];
                result[1] = primes[i];
            }
        }

        return result;      
    }
private:
    bool isPrime(int n) 
    {
        if (n <= 1) 
            return false; // 0 and 1 are not prime
        for (int i = 2; i * i <= n; i++) 
        { // Loop till sqrt(n)
            if (n % i == 0) 
                return false;  // If divisible, not prime
        }
        return true; // Prime if no divisor found
    }
};
