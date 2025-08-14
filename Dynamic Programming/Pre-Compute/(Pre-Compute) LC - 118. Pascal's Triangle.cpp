class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r(numRows);//vector within vector of number of rows numRows
        
        for(int i=0;i<numRows; i++)
        {
            r[i].resize(i+1);//row i will be of size i+1
            r[i][0]=r[i][i]=1;//pattern around outside remains the same
            
            for(int j=1; j<i; j++)//inner loop to take care of numbers between 1's done here
            {
                r[i][j]=r[i-1][j-1]+r[i-1][j];//as value taken from row above, therefore i-1. 
                //columns will be j & j-1 as per pattern.
            }
        }          
        return r;     
    }
};
