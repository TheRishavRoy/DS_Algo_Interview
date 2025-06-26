//Approach-1 (Greedily picking nodes to xor)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    typedef long long ll;

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll  sum        = 0;
        int count      = 0;//count number of times we applied XOR op
        int minLoss = INT_MAX;//the minimum value by XORing a node

        for (ll num : nums) 
        {
            if((num^k) > num) 
            {
                count++;
                sum += (num^k);//we add the better num after ^ operation
            } 
            else 
            {
                sum += num;//else take the unmodified num
            }
            //Tracking minLoss allows us to fix cases where count is odd.
            //If count is even we can just return sum as it is since we can pick both Ui and Vi of the edge
            //But if count is odd we can't pick all the nodes for XOR operation, cuz when we pick an edge we do XOR on 2nodes
            //We have to let one of them go
            //For that we take the minimum of all the XOR sum
            //This values is minLoss

            minLoss = min((long long)minLoss, abs(num - (num ^ k)));//we pick the num that has smallest difference between num and num^k
        }

        if(count%2 == 0)
            return sum;

        return sum - minLoss;
    }
};
