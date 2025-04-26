class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int minPrice=prices[0];//at the start this is the best price. or use INT_MAX
                
        for(int i=0 ; i<prices.size() ; i++)
        {
           minPrice = min(minPrice, prices[i]);//keep track of min price so far
           maxProfit = max(maxProfit, prices[i] - minPrice);//keep track of max Profit that can be made if we sell now at index i
        }
        return maxProfit;
    }
};
