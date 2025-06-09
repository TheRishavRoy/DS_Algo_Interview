//Using DFS by creating an adj list for each group
//eg: r->r,k,s

class Solution {
public:
    char DFS(unordered_map<char, vector<char>> &adj, char curr, vector<bool>& visited) 
    {
        visited[curr-'a'] = true;
        
        char minChar = curr;//min char intialised to cur
        
        for(char &ngbr : adj[curr])//check neighbours to find better minChar 
        {
            if(!visited[ngbr-'a'])
                minChar = min(minChar, DFS(adj, ngbr, visited));//explore all immediate neighbours in DFS manner
        }
        
        return minChar;//return minChar for current group
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
        unordered_map<char, vector<char>> adj; //adj list

        for(int i = 0; i<n; i++) 
        {
            char u = s1[i];
            char v = s2[i];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int m = baseStr.length();//string which e convert to get base string
        string result;

        //now for each char in the base string we call DFS:

        for(int i = 0; i<m; i++) 
        {
            char ch = baseStr[i];            
            vector<bool> visited(26, false);//at start of each group exploration initialise all 26 chars to false             
            result.push_back(DFS(adj, ch, visited));//got the minChar for this group
        }
        
        return result;
    }
};
