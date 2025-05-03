/* 
My leetcode submission: https://leetcode.com/problems/find-eventual-safe-states/submissions/1520031147/ 

Approach: Using DFS to explore all neigbours and to determine if the node lands in safe state.

We make use of a coloring system to mark the nodes:
  Color 0: The node has not been visited yet.
  Color 1: The node is currently being visited (we're in the process of exploring its edges).
  Color 2: The node and all its children can safely lead to a terminal node.
We start our DFS with the unvisited nodes in the graph and explore all their children. 
If we encounter a node that is currently being visited (color 1), this means there is a cycle, and we return False, marking the node as unsafe. 
We continue this process for all nodes, and those that end up marked as color 2 (ie. is safe), are added to our final list of safe nodes.

This approach ensures that we are only considering nodes that lead to terminal nodes as safe, effectively implementing a topological sort, which is suitable for such dependency-based problems.

TC: O(N + E)
SC: O(N)

Company Tag: Google, Facebook, and Amazon 


*/

class Solution 
{
public:
    vector<int> colors; // Color array to mark the states of nodes: 0 = unvisited, 1 = visiting, 2 = safe
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();//number of nodes
        colors.resize(n, 0); // Initialize all nodes as unvisited
        vector<int> safeNodes; // List to hold the eventual safe nodes

        // Check each node to see if it's eventually safe
        for (int i = 0; i < n; ++i) 
        {
            if(dfs(i, graph)) 
            {
                safeNodes.push_back(i); // If it is safe, add it to the list
            }
        }

        return safeNodes; // Return the list of safe nodes
    }

    // Depth-first search to determine if a node is safe
    bool dfs(int nodeIndex, vector<vector<int>>& graph) 
    {
        if (colors[nodeIndex]) 
        {
            //If it was marked as 1 (currently visiting, indicating a cycle), 
            //It means this path leads to a cycle
            // If the node has been visited already, return true only if it's marked as safe
            return colors[nodeIndex] == 2;
        }

        colors[nodeIndex] = 1; // Mark the node as visiting
        for (int neighbor : graph[nodeIndex])//neighbours we can  visit from node at nodeIndex 
        {
            // Explore all the neighbors of the current node
            if (!dfs(neighbor, graph)) 
            {
                // If any neighbor is not safe, the current node is not safe either
                return false;
            }
        }
        
        //If the loop completes without finding any unsafe neighbors, 
        //it means all paths from the current nodeIndex lead to safe nodes or terminal nodes.
        colors[nodeIndex] = 2; // Mark the node as safe
        return true; // Return true as the node is safe
    }
};
