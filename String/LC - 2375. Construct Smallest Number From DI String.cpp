//Approach-1 - (Simple brute force)
//T.C : O(n * (n+1)!), (n+1)! permuations and n for matchesPattern()
//S.C : O(n+1) for result
class Solution {
public:
    bool matchesPattern(string &num, string &pattern) {
        for(int i = 0; i < pattern.length(); i++) {
            if((pattern[i] == 'I' && num[i] > num[i+1]) || (pattern[i] == 'D' && num[i] < num[i+1])) 
            {
                return false;
            }
        }

        return true;
    }

    string smallestNumber(string pattern) {
        int n = pattern.length(); //"IID" , n = 3
        string num = "";
        
        for(int i = 1; i <= n+1; i++) {
            num.push_back(i + '0'); //i+'0' will convert i into string. since num is a string
        }

        //e.g if III; num = "1234" number of digit will be 1 more

        while(!matchesPattern(num, pattern)) 
        {
            next_permutation(begin(num), end(num));
        }

        return num;

    }
};



//=============================================Stack solution(optimal)============================================================

//Approach-2 - (Simple using string as a stack) - You can use a stack<int> as well
//T.C : O(n)
//S.C : O(n) for the result
class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();

        string num = ""; //(n+1) //index 0 to index n

        int counter = 1;
        stack<char> st;

        for(int i = 0; i <= n; i++) {
            st.push(counter + '0');
            counter++;

            if(i == n || pattern[i] == 'I') {
                while(!st.empty()) {
                    num += st.top();
                    st.pop();
                }
            }
        }

        return num;

    }
};
