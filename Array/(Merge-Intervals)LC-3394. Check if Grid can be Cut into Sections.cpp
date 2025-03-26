class Solution {
 public:
  bool checkValidCuts(int n, vector<vector<int>>& rectangles) 
  {
    vector<pair<int, int>> xs;
    vector<pair<int, int>> ys;

    for (vector<int> rectangle : rectangles) 
    {
      int startX = rectangle[0];
      int startY = rectangle[1];
      int endX = rectangle[2];
      int endY = rectangle[3];
      xs.emplace_back(startX, endX);
      ys.emplace_back(startY, endY);
    }

    return max(countMerged(xs), countMerged(ys)) >= 3;//either one of them vertical or horizontal should return >= 3 unique section. it will take atleast 3 unique section to give 2 vertical/horizontal cuts.
  }

 private:
  int countMerged(vector<pair<int, int>>& intervals) 
  {
    int uniqueCount = 0;
    int prevEnd = 0;

    sort(intervals.begin(),intervals.end());

    for (const auto& [start, end] : intervals)
      if (start < prevEnd) //overlapping
      {
        prevEnd = max(prevEnd, end);//extend previous interval's end to new interval's end
      } 
      else //non - overlapping
      {
        prevEnd = end;//update new prevEnd
        ++uniqueCount;//uniqueCount increase
      }

    return uniqueCount;
  }
};
