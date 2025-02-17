//T.C : O(n!)//since there are n numbers, each with potential positions to place.
//S.C : O(n)
//Using backtracking
class Solution {
public:

    bool solve(int i, int n, vector<int>& result, vector<bool>& used) 
    {
        if(i >= result.size()) //we have reached answer
        {
            return true; //gauranteed answer - we were filling largest numbers first
        }

        if(result[i] != -1) //If the current position is already filled, move to the next position.
        {
            return solve(i+1, n, result, used);
        }

        //Attempt to place the numbers starting from n (largest first) to ensure the largest numbers get priority in placement, as smaller numbers are easier to fit later.
        for(int num = n; num >= 1; num--) 
        {
            if(used[num]) //if already used
            {
                continue;//move to next number
            }

            //try Placing the Number:
            used[num] = true;//Mark the number num as used and place it at position i.
            result[i] = num;

            //EXPLORE
            if(num == 1) 
            {
                if(solve(i+1, n, result, used) == true) //we move on to next idx i+1 and continue building
                {
                    return true;//If the recursive call successfully finds a valid sequence, we immediately return true
                }
            } 
            else //we have to take care of second occurrence at "j"
            {
                int j = result[i] + i;//distance between the two positions is exactly num - 1

                if(j < result.size() && result[j] == -1) //if it is within boundary and currently unoccupied (result[j] == -1).
                {
                    result[j] = num;//pace num at idx j
                    if(solve(i+1, n, result, used) == true) //and continue to find solution
                    {
                        return true;//if we get true in above check, which mean sequence is valid, so return true
                    }
                    result[j] = -1;//If placing num at position j does not lead to a valid sequence, undo the placement by clearing result[j].
                }
            }

            //UNDO the first place also as part of backtracking
            used[num] = false;//Undo the decision to use num
            result[i] = -1;//Undo the placement of num at position i. Set it back to -1 so it can be used for other possibilities
        }

        return false;//if we can't return true(find a vlid sequence), return false
    }

    vector<int> constructDistancedSequence(int n) 
    {
        vector<int> result(2*n-1, -1);//size of my resultant vector, because every number exept 1 appears twice in the sequence

        vector<bool> used(n+1, false);//to keep track used numbers

        solve(0, n, result, used);//call helper function {idx,integer_n,result_vector,used_vector}

        return result;
    }
};
