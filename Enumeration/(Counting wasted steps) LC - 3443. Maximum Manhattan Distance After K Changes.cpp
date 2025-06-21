class Solution {
public:
    int maxDistance(string s, int k) {
        int maxMD = 0;

        int east = 0;
        int west = 0;
        int north = 0;
        int south = 0;

        for(int i = 0; i < s.length(); i++) {

            if(s[i] == 'E') 
                east++;
            else if(s[i] == 'W') 
                west++;
            else if(s[i] == 'N') 
                north++;
            else if(s[i] == 'S') 
                south++;

            int currMD = abs(east-west) + abs(north-south);
            
            //NOTE: you can change at most k characters to any of the four directions.

            int steps  = i+1;//number of moves made, ideally your MD should increase by steps unit 
            int wasted = steps - currMD;//Calculates how many of those steps didn't help increase MD

            int extra = 0;
            if(wasted != 0) //if some steps were wasted. steps != currMD
            { 
                /*You’re given up to k “power-ups” or adjustments, 
                each of which can potentially reclaim 2 units of distance 
                (1 move away from the origin and 1 step not canceling it out). 
                So the maximum adjustment is 2 * k, 
                but you can't correct more than the actual number of wasted steps.*/
                extra = min(2*k, wasted);
            }

            int finalCurrentMD = currMD + extra;

            maxMD = max(maxMD, finalCurrentMD);
        }

        return maxMD;
    }
};
