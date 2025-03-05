class Solution {
public:
    long long coloredCells(int n) 
    {       
            //from patten we can see at every step :
            //n^2+(n-1)^2
            return (1LL * n * n) + (1LL * (n - 1) * (n - 1));
            //n^2: Number of cells in the current layer
            //(n-1)^2: Number of cells in the previous layers combined
            //Always use 1LL * a * b whenever you are multiplying two integers that might exceed INT_MAX.
    }
};
