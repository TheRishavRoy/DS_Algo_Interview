class Solution {
public:
    void solve(int cur, int n,vector<int> &result)
    {
        if(cur>n)//if we have excedded max number possible for this enumeration
            return;

        result.push_back(cur);//cur will always get pushed first

        //now we start appending
        for(int i =0; i<=9; i++)
        {
            int newNum=cur*10+i;//form next number in the enumeration
            if(newNum>n)//check for boundary
                return;
            solve(newNum, n, result);//recursive call over new current number
        }

    }
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for(int i=1 ; i<=9; i++)//we start generating from 1 and go uptil 9
        {
            solve(i, n, result);
        }
        return result;
    }
};
