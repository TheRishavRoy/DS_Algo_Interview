//Approach-1 (Using simple recursion to find subsets)
//T.C : O(2^n)
//S.C : O(1)
class Solution {
public:
    //O(2^n)
    int countSubsets(int idx, int currOr, vector<int>& nums, int maxOr) 
    {
        if(idx == nums.size()) //if we have parsed all the index
        {
            if(currOr == maxOr)//and found a subset = maxOR
            {
                return 1; //Found one subset
            }    

            return 0;
        }

        //Number of subset with maxOR if  :  Take nums[idx]
        int takeCount = countSubsets(idx+1, currOr | nums[idx], nums, maxOr);

        //Number of subset with maxOR if  :  Not taken nums[idx]
        int notTakeCount = countSubsets(idx+1, currOr, nums, maxOr);


        return takeCount + notTakeCount;//return number of subset with maxOR so far from recursive calls
    }

    int countMaxOrSubsets(vector<int>& nums) 
    {
        int maxOr = 0;
        for(int &num : nums) //we have to find OR with each number since it will give us the best chance of setting all the bits by using OR operation
        {
            maxOr |= num;
        }

        int currOr = 0;
        return countSubsets(0, currOr, nums, maxOr);
    }
};
