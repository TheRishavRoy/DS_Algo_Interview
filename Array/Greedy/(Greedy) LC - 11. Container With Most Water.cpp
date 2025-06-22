class Solution
{
public:
	int maxArea(vector<int> &heights)
	{
		int n=heights.size();
		int left=0;
		int right=n-1;
		int maxCollectedWater=0;//our result
		
		while(left<right)
		{
			int localHeight=min(heights[left],heights[right]);//take the bounded height
			int localWidth=right-left;//cacualte local width
			maxCollectedWater=max(maxCollectedWater,localHeight*localWidth);
			
            		//apply greedy method in choosing:
            		if(heights[left]<heights[right])//whichever will be more benificial.
			{
				++left;//find better left bar
			}
			else
			{
				--right;//find better right bar
			}
		}
		return maxCollectedWater;
	}
};
