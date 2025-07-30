class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int Max=0;
        int maxLen=0;
        int streak=0;
        
        for(int num:nums)
        {
           if(num>Max)//found a new Max, now we will see how long a streak is there for new Max
           {
                streak=1;//restarted streak count starting from current element
                Max=num;//updated Max with new Max
                maxLen=0;//the previous maxLen is now redundant after finding new max
           }
           else if(num==Max)
           {
                ++streak;//continuing the streak since this time also num==Max
           }
           else
           {
                streak=0;//have to restart the streak since the streak of current Max has ended
           }
           maxLen=max(maxLen,streak);//update max streak
        }      
        return maxLen;
    }
};
