class Solution 
{
public:
    int rotatedDigits(int n) 
    {
        int count = 0;
        
        for (int i = 1; i <= n; i++) 
        {
            int curNum = i;
            int rotatedNum = 0;
            bool isDifferent = false;
            bool isValid = true;//default true later make it invalid when we get an invalid digit

            while (curNum > 0) 
            {
                int rem = curNum % 10;
                
                // Handle invalid digits
                if (rem == 3 || rem == 4 || rem == 7) 
                {
                    isValid = false;//chnage isValid to false
                    break;//check next number
                }

                // Rotate valid digits
                if (rem == 2) 
                    rem = 5, isDifferent = true;//mirror the digit and set isDifferent to true
                else if (rem == 5) 
                    rem = 2, isDifferent = true;
                else if (rem == 6) 
                    rem = 9, isDifferent = true;
                else if (rem == 9) 
                    rem = 6, isDifferent = true;

                //need not check for 0,1,8 since default isDifferent is false for every Number
                rotatedNum = rem * 10 + rotatedNum;
                curNum /= 10;
            }
            
            if (isValid && isDifferent) //has to be both valid and different from other numbers
                count++;
        }
        
        return count;
    }
};

