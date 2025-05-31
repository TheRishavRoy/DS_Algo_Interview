class Solution 
{
public:
    // traversal function for shortest path calculation
    void traverseFromSource(int startNode, vector<int>& edges, vector<int>& dist) 
    {
        int d = 0;
        int cur = startNode;
        while (cur!=-1 && dist[cur] == -1) // Stop on no outgoing edge or visited node. If there is no outgoing edge from i, then edges[i] == -1.
        { 
            dist[cur] = d++;//post increment since dist to source = 0, subsequent nodes gets +1 added 
            cur = edges[cur]; // Move to next node, since each node has atmost one outgoing edge
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        
        // Step 1: Compute shortest distances from node1 and node2
        vector<int> dist1(n, -1), dist2(n, -1);
        
        traverseFromSource(node1, edges, dist1); // Compute distances from node1
        traverseFromSource(node2, edges, dist2); // Compute distances from node2

        // Step 2: Find the optimal meeting node
        int minDistance = INT_MAX;
        int result = -1;

        for (int i = 0; i < n; i++) 
        {
            if (dist1[i] != -1 && dist2[i] != -1) 
            { 
                // Reachable from both
                int maxDist = max(dist1[i], dist2[i]); // Max distance from either node
                if (maxDist < minDistance) 
                {
                    minDistance = maxDist;
                    result = i;
                }
            }
        }
        return result;
    }
};
