/*
Approach: DP+Dijkstra
==========
1. Use a priority queue (min-heap) to implement Dijkstra’s algorithm. 
   The priority queue (min-heap) helps process nodes in increasing order of distance.
2. Keep track of the shortest distance to each node. 
   The dist array keeps track of the shortest distance to each node.
3. Maintain ways[i], which stores the number of ways to reach i using the shortest distance.
4. Update the count whenever we find another shortest path to i.

This is a classic DP subproblem:
State: ways[v] stores the number of shortest paths to node v.
Transition: If a new shortest path is found → update; If another shortest path of the same length is found → add.


TC:
==========
O(log V) for priority queue operations.
O((V + E) log V)
*/
class Solution 
{
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adjList(n);//adjacency list representation of the graph, 
        //where each node stores a list of pairs {neighbor, weight}.

        for (auto& road : roads) //iterate through all roads
        {
            int u = road[0];//start node
            int v = road[1];//end node
            int wt = road[2];//weight of edge
            adjList[u].emplace_back(v, wt);//(or)push_back(make_pair(v, wt)) which is less efficient than emplace_back
            adjList[v].emplace_back(u, wt);
        }
        
        // Min-heap for Dijkstra {distance, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        //This declarartion is fine for C++17 or later. where we write greater<> in which CTAD(class Template argument deduction) feature will deduce template parameter (pair<long long, int> in this case) automatically
        //otherwise we have to define: greater<pair<long long, int>> explicitly

        vector<long long> dist(n, LLONG_MAX);//each element is initialized to LLONG_MAX(Infinite)
        vector<int> ways(n, 0);//initialised to 0 for n nodes

        pq.push({0, 0});//start at node zero wich has distance zero {distance,node} 
        dist[0] = 0;//The source node has a distance of 0 to itself.
        ways[0] = 1;//number of ways to reach is 1. There is one way to reach the source (itself).

        while (!pq.empty()) 
        {
            auto [d, u] = pq.top();
            /*
            pair<long long, int> topElement=pq.top();
            long long d=topElement.first;
            int u=topElement.second;
            */
            pq.pop();
            
            if (d > dist[u]) 
                continue; // Ignore outdated distances
            
            for (auto &[v, w] : adjList[u]) //for node u, for all neighbour, we find out v and weight.
            {
                long long newDist = d + w;//Calculates the new potential shortest distance to reach v through u.
                
                if (newDist < dist[v]) //shorter way to reach v through u
                {
                    // Found a new shortest path
                    dist[v] = newDist;
                    ways[v] = ways[u];//reset for v. since all previous ways for v are now obsolete.
                    pq.push({newDist, v});//into the priority queue to process v next.
                } 
                else if (newDist == dist[v]) 
                {
                    // Found another way to reach v with the same shortest distance
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        
        return ways[n - 1];//Since Dijkstra ensures that we only update ways[v] when finding the shortest path, ways[n - 1] will contain the total number of ways to reach the last node optimally.
    }
};
