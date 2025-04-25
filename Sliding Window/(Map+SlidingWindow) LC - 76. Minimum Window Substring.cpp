class Solution {
public:
    string minWindow(string s, string t) 
    {
        int n = s.length();
        if(t.size()>n)//if t itself is larger then,
            return "";//return empty string

        map<char, int> mp;//map to store current freq of each character, specially the one required in t
        
        for(char &ch : t) 
        {
            mp[ch]++;//moving through t we record all character's fre in map
        }
        
        int requiredCount = t.length();//we store required count and decrement/increment whenever we see ant element within t

        int i = 0, j  = 0;//i and j are two pointers used for parsing through s
        int minStart  = 0;
        int minWindow = INT_MAX;

        while(j < n) //while j does not go out of bound. we keep trying to find smallest window size.
        {
            char ch_j = s[j];//pick first character
            if(mp[ch_j] > 0)//if its freq in map is >0, then we need it
                requiredCount--;//so decrement from req count
            
            mp[ch_j]--;//and decrease fre in map as well
            
            while(requiredCount == 0) //if we get to req=0
            { //try to shrink the window
                //before shrinking:-----------------------------------------------------------------
                if(minWindow > j-i+1) //also calculate current window size see if it is smaller than 
                //previous minWindow
                {
                    minWindow = j-i+1;//if yes then update it to curWindow
                    minStart  = i;//update i's location
                }
                //----------------------------------------------------------------------------------
                //now that we start to shrink:
                char ch_i = s[i];
                mp[ch_i]++;//we increase the frequency of s[i]

                if(mp[ch_i] > 0)//if frequency is greater than 0 which means it is required in t
                    requiredCount++;//increment
                
                i++;//and we move forward trying to shrink the window
            }
            //if required count is no longer 0 which means we have go searching again so j++
            j++; //Don't ever forget this :-)
        }
        
        return minWindow == INT_MAX ? "" : s.substr(minStart, minWindow);//take substring starting from minStart and length will be minWindow
    }
};
