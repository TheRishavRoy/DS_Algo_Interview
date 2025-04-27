class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len=strs.size();
        
        if(len==0)
            return "";        
        
        sort(strs.begin(),strs.end());      
        //since we hv sorted it. we only hv to parse for the length of shortest string i.e. str[0]
        
        //since they are sorted, if first and last element hv things in common so will the middle one
        string a=strs[0];
        string b=strs[len-1]; 

        string res="";
        
        for(int i=0; i<a.size(); i++)
        {
            if(a[i]==b[i])
            {
                res = res + a[i];//keep adding common prefix
            }
            else
            {
                break;//terminate, no more common prefix
            }
        }     
        return res;
    }
};
