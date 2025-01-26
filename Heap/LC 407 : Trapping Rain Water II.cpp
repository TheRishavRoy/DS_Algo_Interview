/*
My leetcode solution: 
https://leetcode.com/problems/trapping-rain-water-ii/submissions/1517957006/
We maintain a Pair of {height,Pair of {co-ordinates}}
We start of with our boundary cells. This is because we need to know eventually how much water will get trapped AND the water trapped even in inner cells can be effected by our boundary cells.

we put our boundary cells in priority queue beacause we starting with smallest height cells we wil explore its neighbour to see how much water gets trapped in that particular cell.
If we start from a larger value, anyway no water might get stored there is it is higher than its neighbour.

T.C : O(m*n log(m*n))
S.C : O(m*n)

Company tag: Twitter, Google

*/
class Solution {
public:
    typedef pair<int, pair<int, int>> PP;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};//right,down,left,top

    int trapRainWater(vector<vector<int>>& heightMap) 
    {
        int m = heightMap.size();//rows
        int n = heightMap[0].size();//cols

        priority_queue<PP, vector<PP>, greater<>> boundaryCells;//pair : {height, co-ordinates{i,j}} 
        //container here is greater<> which means min heap

        vector<vector<bool>> visited(m, vector<bool>(n, false));//to keep track of visited cells

        for (int r = 0; r < m; ++r) 
        {
            for (int c : {0, n - 1}) //we traverse the left most col and right most col
            { //0 : left most boundary, cols-1 : right most boundary
                boundaryCells.push({heightMap[r][c], {r, c}});
                visited[r][c] = true;
            }
        }

        for (int c = 0; c < n; ++c) 
        {
            for (int r : {0, m - 1}) //we traverse first and last row
            { //0 : top most boundary, rows-1 : bottom most boundary
                boundaryCells.push({heightMap[r][c], {r, c}});
                visited[r][c] = true;
            }
        }
        //=========now we have all boundary cells in pq===========

        int trappedWater = 0;//trapped water

        while (!boundaryCells.empty())//while queue is non-empty 
        {
            auto [height, cell] = boundaryCells.top();//OR we can write : PP = boundaryCells.top(); int height=PP.first; int i=PP.second.first; int j=PP.second.second;
            boundaryCells.pop();// since we hv stored the top element

            //now we got the height
            int i = cell.first;//x co-ordinate
            int j = cell.second;//y co-ordinate

            //for all neighbours:
            for (vector<int>& dir : directions) 
            {
                int i_ = i + dir[0];//take new x-coordinate
                int j_ = j + dir[1];//tae new y-coordinate

                if (i_>=0 && i_<m && j_>=0 && j_<n && !visited[i_][j_]) //if neigbour is within boundary & not visited
                {
                    
                    trappedWater += max(0, height - heightMap[i_][j_]);//if current height is greater than neighbour, the current cell can trap water. This is what we are hoping for.
                    //amount of water stored is the height difference
                    //max of 0 & difference because we don't want -ve value to go into the answer
                    
                    boundaryCells.push({max(height, heightMap[i_][j_]), {i_, j_}});//now we push the neighbour into queue for further processing.
                    //we push: Max of current_height and height_of_neighbour, so that neighbour's neighbour can also know till what max height water can be trapped in their cell.
                    //we push: i_ and j_ since its neigbours are to be explored
                    
                    visited[i_][j_] = true;//current neighbour marked visited since it is already processed and added to queue for further processing
                }
            }
        }
        return trappedWater;
    }
};
