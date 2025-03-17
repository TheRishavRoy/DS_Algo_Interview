class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) 
    {
        // The minimum time required to fix at least one car is 1 unit, if fastest mechanic(rank1) is working on it.
        long long left = 1;        
        
        //If this fastest mechanic repairs all cars, the worst-case time would be: 
        //(cars * cars) * (*min_element(ranks.begin(), ranks.end()))
        long long right = (long long)cars * cars 
                        * (*min_element(ranks.begin(), ranks.end()));       
                            
        //perform binary search to find minimum time rquired to fix all cars
        while (left < right) 
        {
            long long mid = left + (right - left) / 2;//time given so far
            if (canRepair(ranks, cars, mid)) 
                right = mid; // Try to minimize time to fix all cars
            else 
                left = mid + 1; // Increase time, we will require more time to fix all cars
        }
        return left;
    }

private:
    bool canRepair(vector<int>& ranks, int cars, long long maxTime) 
    {
        long long totalCars = 0;//cars fixed
        for (int rank : ranks) 
        {
            totalCars += (long long)sqrt(maxTime / rank); // Cars repaired in given time, car=sqrt(time/rank) since time=(car^2)*rank
            if (totalCars >= cars) //if we have repaired all cars 
                return true;
        }
        return false;//did not repair all cars
    }
};
