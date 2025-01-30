class Solution 
{
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n = edges.size();
        //number of nodes = n
        //number of edges = n

        unordered_map<int, vector<int>> adj;
         //Each edge in edges is a pair of integers [u, v]   

         for(int i = 0; i < n; i++) 
         {
            int u = edges[i][0];//first end point of an edge
            int v = edges[i][1];//second end point of an edge. {u,v} in edges
            
            vector<bool> visited(n, false);//mark all as unvisted
            //if we come across a redundant edge , u and v must be already present in adj, added by some previous edges
            //which means we can now apply DFS and check if u and v are already connected
            //if u and v are already connected somehow, it means that our present edge between u and v becomes redundant
            if(adj.find(u) != adj.end() && adj.find(v) != adj.end() && dfs(adj, u, v, visited)) 
            {
                return edges[i];//return redundant edge
            }
            adj[u].push_back(v);//we create adj list if edge notpresent in list
            adj[v].push_back(u);
        }
        return {};//if no redundant
    }
private:
    bool dfs(unordered_map<int, vector<int>> &adj, int u, int v, vector<bool>& visited) 
    {
        visited[u] = true;

        if(u == v) //means the are connected
        {
            return true;//return they are connected
        }

        for(int &ngbr : adj[u])//explore neigbours 
        {
            if(visited[ngbr]) //if neighbour already visited continue to next neighbour
                continue;

            if(dfs(adj, ngbr, v, visited)) //if not visited, expolre dfs on this neighbour recursively
            {
                return true;//return true if dfs returns true for connected
            }
        }

        return false;//else in the end return not connected

    }

};
