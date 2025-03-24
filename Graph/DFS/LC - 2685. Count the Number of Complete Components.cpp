/*
Approach DFS: 
- Use iterative DFS from node 0 to n-1
- if nodes is unvisted (might be a new component), run DFS till completion
- Once a DFS terminates , one component is traversed. So calculate condition for complete conected component
    edges/2=n*(n-1)/2
- edges/2 because each edge counted twice

*/
class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited, int &nodes, int &edges) 
    {
        visited[node] = true;
        nodes++;
        edges += adjList[node].size(); // Number of edges added will be list of edges of this node in adjList
        //each edge counted twice

        for (int ngbr : adjList[node]) //explore ngbr
        {
            if (!visited[ngbr]) 
            {
                dfs(ngbr, adjList, visited, nodes, edges); //call dfs if ngbr is unvisited
            }
        }
        //the function returns once a particular component is traversed completly
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> adjList(n); 
        
        for (auto &edge : edges) 
        {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        } // adjacency list created 

        vector<bool> visited(n, false);
        int completeComponent = 0;

        // Iterative DFS from 0 to n-1
        for (int idx = 0; idx < n; idx++) 
        {
            if (!visited[idx]) //if node is unvisited
            {
                int nodes = 0;//nodes helps count the total nodes in a component.
                int edges = 0;//for every component we start with 0

                dfs(idx, adjList, visited, nodes, edges);

                //when one component is over dfs terminates, we calculate if it is complete
                if (edges / 2 == nodes * (nodes - 1) / 2)//since each edge counted twice so edge/2
                    completeComponent++;
            }
        }
        return completeComponent;
    }
};
