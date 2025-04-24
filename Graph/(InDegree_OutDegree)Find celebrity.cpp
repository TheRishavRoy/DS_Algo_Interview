/*
Description:
===============
A celebrity is a person who is known to all but does not know anyone at a party. 
A party is being organized by some people. A square matrix mat[][] (n*n) is used to represent people at the party 
such that if an element of row i and column j is set to 1 it means ith person knows jth person. 
You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.
*/
int findCelebrity(vector<vector<int>>& matrix) 
{
    int n=matrix.size();
    vector<int> indegree(n, 0);
    vector<int> outdegree(n, 0);

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(matrix[i][j] == 1)
            {
                ++outdegree[i];
                ++indegree[j];
            }
        }
    }

    for(int i = 0; i < n; ++i){
        if(indegree[i] == n - 1 && outdegree[i] == 0)
            return i;  // Found the celebrity
    }

    return -1;
}
