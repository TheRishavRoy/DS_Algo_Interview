class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());//sort based on start point
        vector<vector<int>> result;
        for(int i=0;i<intervals.size();i++)
        {
            if(result.empty() || result.back()[1]<intervals[i][0])//if end point of prev interval is less than start point of present interval
            {                
                vector<int> v={intervals[i][0],intervals[i][1]};//collect them in a vector
                result.push_back(v);//push back to result vector
            }
            else//if ovelapping then, update the end point of previous interval 
            {
                result.back()[1]=max(result.back()[1],intervals[i][1]);
            }
        }
        return result;       
    }
};
