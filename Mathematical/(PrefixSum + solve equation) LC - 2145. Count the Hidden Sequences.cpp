class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) 
    {
        //e.g.: hidden[2] = x + diff[0] + diff[1]  
        //therefore: hidden[i] = x + prefixSum[i]
        long long minPrefix=0;
        long long maxPrefix=0;
        long long current=0;
        for(auto &diff:differences)
        {
            current+=diff;//keep adding diff
            minPrefix = min(minPrefix, current);//calculate the min prefix 
            maxPrefix = max(maxPrefix, current);//calculate the max prefix
            //e.g if prefixSums(min and max) are 0,-2,1,2
            //we keep adding to a value say x
            //so, hidden seq: x,x-2,x+1,x+2
        }   
        //now solve for say limit = [1.6]
        //therefore x-2>=1 => x=3
        //x+2<=6 => x=4
        //this gives us two valid seq x=3,4
        return max(0LL, (upper - lower) - (maxPrefix - minPrefix) + 1);
    }
};
