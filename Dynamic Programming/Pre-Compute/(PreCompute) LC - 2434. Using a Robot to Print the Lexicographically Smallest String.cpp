//Using DP(Precompute)
class Solution {
public:
    string robotWithString(string s) 
    {
        int n=s.size();
        
        //DP: Precompute the min character to the right
        vector<char> minCharToRight(n);
        minCharToRight[n-1]=s[n-1];
        for(int i=n-2 ; i>=0 ; --i)
        {
            minCharToRight[i]=min(s[i],minCharToRight[i+1]);
        }
        
        string t = "";//given in question
        string paper = "";//given in question

        int i = 0;
        while(i<n)
        {
            t.push_back(s[i]);//we do this anyway for each operation

            //but before writting it to paper
            //we check minimum character to right of i, not minimum character at i
            char minChar=(i+1 < n) ?minCharToRight[i+1]:s[i];//minChar to right of i, not at i

            //how long we keep writing to the paper?
            //while t.back() is less than smallest character to the right
            //thats because t.back() is smaller than smallest right character

            while(!t.empty() && t.back()<=minChar)
            {
                paper+=t.back();
                t.pop_back();
            }
            i++;
        } 

        //write to paper whatever is left in t
        while(!t.empty())
        {
            paper+=t.back();
            t.pop_back();
        }
        return paper;
    }
};
