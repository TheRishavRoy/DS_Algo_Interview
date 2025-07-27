class Solution {
public:
    int maxSum(vector<int>& nums) 
    {
        unordered_set<int> st;

        int sum = 0;
        int maxNeg = INT_MIN;//Tracks the maximum negative number 
        //in case there are no positives.
        //return the most tolerable negative (maxNeg).

        for(int &num : nums) 
        {
            if(num <= 0) 
            {
                maxNeg = max(maxNeg, num);
            } 
            else if(!st.count(num)) //if num is not in st, i.e unique
            {
                sum += num;//calculate it in sum
                st.insert(num);//put it in set to avoid duplicates
            }
        }        
        return sum == 0 ? maxNeg : sum;//if all negative return max neg i.e. closest to 0
    }
};
