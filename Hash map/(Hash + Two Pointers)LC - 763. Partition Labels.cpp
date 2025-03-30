class Solution 
{
public:
    vector<int> partitionLabels(string s) 
    {
        unordered_map<char,int> lastSeen;
        for(int i=0 ; i<s.size() ; i++)
        {
            lastSeen[s[i]]=i;
        }
        vector<int> intervals;
        int start = 0/*start of a new partition*/;
        int end = 0;
        /*
        - Point 1:  As we traverse the string, we keep expanding the end boundary to ensure all occurrences of characters in the current partition are included.
        - Point 2: End represents the farthest right index we must include to ensure all instances of characters encountered so far are within the partition.
    */
        for(int i=0 ; i<s.size() ; i++)
        {
            end=max(end,lastSeen[s[i]]);

            if(i==end)//if i==end this means idx i is the end of all the elements included in partition . Point 1 & 2.
            {
                intervals.push_back(end-start+1);
                start=i+1;//start of next partition
            }
        }
        return intervals;
    }
};
