class Solution {
public:
    int tupleSameProduct(vector<int>& nums) 
    {
        int n=nums.size();
        if(n<4)
            return 0;
        
        unordered_map<int,int> productCount;

        for(int i=0; i<n ; i++)
        {
            for(int j=i+1; j<n ; j++)
            {
                int product=nums[i]*nums[j];
                ++productCount[product];//increse the count of this product
            }
        }
        int answer=0;
        for(auto& [product,count]:productCount)
        {
            //we have two plave to fill __ = __ and we have n products
            //hence we will use nC2 combination formula
            //nC2= n*(n-1)/2
            answer+=count*(count-1)/2;
        }
        //now each tuple can be arranged in 8 ways:
        // Each tuple can be permuted in 8 different ways since the tuple (a, b, c, d)
        // can give us 2 distinct equations by swapping the pairs: a*b = c*d AND a*c = b*d,
        // and each equation has 4 permutations (a * b, b * a, c * d, d * c).
        return answer * 8;
    }
};
