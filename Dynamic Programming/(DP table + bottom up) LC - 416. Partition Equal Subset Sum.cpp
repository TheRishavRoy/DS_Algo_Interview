//Approach-2 (Using Bottom Up same as LIS) - Just need to keep track of how to print LIS Longest Increasing Subsequence
//T.C : O(n^2)
//S.C : O(n)
/*
The idea here is :
  - initialise a dp table for Longest subset so far to 1, vector<int> dp(n,1)
  - once we find nums[i]%num[j]==0 which means we update the length in dp[i] to dp[j]+1, i.e. 1 sequence longer
  - we store j into list of prev_idx since later we backtrack(bottom up) to form result vector
  - if dp[i] is > maxLen so far we got a candidate for the answer. We store its index i.e. index i the last_max_idx
  - Now form result vector starting from  last_max_idx and go back using list of prev_idx, to form our answer 
*/



class Solution 
{
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        sort(begin(nums), end(nums));//we first sort the array. so that if b is divisible by a and c is divisible by b then anyway c is divisible by a.
        //if nums[i]%nums[j] ==0 and nums[j]%k == 0 then nums[i]%nums[k]==0
        //we don't have to compute again

        int n = nums.size();
        vector<int> t(n, 1);//dp table to keep track of longest divisble subset seen so far till this index
        //we keep adding to it as we keep finding divisible element

        vector<int> prev_idx(n, -1);//In the end we need to form a result(subset), so we keep track of previous index that gave us the next element of the subset

        //so we can trace back in the vector to get our result subset 
        int last_chosen_index = 0;//last index where i got my maximum element i.e. last position of i where we found element in subset.
        int maxL = 1;//intialize maximum len

        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < i; j++)//j<i because we want to check nums[i]%nums[j]
            {
                if(nums[i]%nums[j] == 0) //if nums[i] is divisble by nums[j]
                {
                    //now we check dp table to see if t[i] needs to be updated now that nums[i]%nums[j]
                    
                    if(t[i] < t[j]+1) //if t[i] is less than value of t[j]+1 then update the dp table
                    {
                        t[i] = t[j]+1;//we update t[i] by adding 1 to value at t[j]
                        prev_idx[i] = j;//we store index of where we got this element which was divisible
                    }

                    if(t[i] > maxL) 
                    {
                        maxL = t[i];//we update max length found so far
                        last_chosen_index = i;//and we increment the index from where we start looking next time
                    }
                }
            }
        }

        vector<int> result;
        while(last_chosen_index >= 0) //while we don't se -1 in vector we keep tracing
        {
            result.push_back(nums[last_chosen_index]);//keep tracing back and pushing element to result
            last_chosen_index = prev_idx[last_chosen_index];//we update the index every time as we go backwards
        }

        return result;
    }
};
