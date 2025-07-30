/*
Dry run to understand better
=================================================
Initial setup:
    output = [""]
    maxLen = 0
Now iterating over each word in arr:
--------------------------------------------------
1st Word: "un"
    output.size() = 1, so only 1 iteration:
        temp = "" + "un" = "un"
        us = {'u', 'n'} → size = 2 == temp.size() → valid
        Add "un" to output → output = ["", "un"]
        Update maxLen = max(0, 2) = 2

2nd Word: "iq"
    output.size() = 2 since output = ["", "un"] , so 2 iteration:
    Iteration 1:
        temp = "" + "iq" = "iq" → unique → ✅
        Add "iq" → output = ["", "un", "iq"]
        maxLen = max(2, 2) = 2
    Iteration 2:
        temp = "un" + "iq" = "uniq" → all unique → ✅
        Add "uniq" → output = ["", "un", "iq", "uniq"]
        maxLen = max(2, 4) = 4

3rd Word: "ue"
    output = ["", "un", "iq", "uniq"], so 4 iteration:
    Iteration 1:
        temp = "" + "ue" = "ue" → ✅
        Add "ue" → output = ["", "un", "iq", "uniq", "ue"]
        maxLen = max(4, 2) = 4
    Iteration 2:
        temp = "un" + "ue" = "unue" → has duplicate 'u' → ❌
    Iteration 3:
        temp = "iq" + "ue" = "ique" → ✅
        Add "ique" → output = ["", "un", "iq", "uniq", "ue", "ique"]
        maxLen = max(4, 4) = 4
    Iteration 4:
        temp = "uniq" + "ue" = "unique" → duplicate 'u' and 'e' → ❌


maxLen = 4
*/
class Solution {
public:
    int maxLength(vector<string>& arr) 
    {
        vector<string> output = {""};      //size=1
        int maxLen = 0;//keep track of max concatination obtained
        for (string word : arr)//for each word in array 
        {
            for (int i = 0; i < output.size(); i++) //concatinate with each output[i] of current output[] vector elements {"","un","iq"...}
            {
                // 2. Create a string by combining out vector's element and input word
                // temp = "uniq", "unue"....
                string temp = output[i] + word;//inside temp string we concatinate input word to see if it has repetative character 
                //we concatinate with  all the previous obtained output[i]

                // 3. Find repetative characters,
                //  a. Insert word into set "unue"=>"une"
                //  b. if input word size != unorderedSet.size "unue"!="une" (Repeating Found), Skip this word
                unordered_set<char> us(temp.begin(), temp.end());
                if (temp.size() != us.size())//if size of two strings are now unequal
                    continue;//means there is a duplicate so move on to next word

                // if combined string is valid, e.g. "uniq" , insert into output[] vector 
                output.push_back(temp);
                //output = ["", "un",...]
                maxLen = max(maxLen, (int)temp.size());//update max temp seen so far, i.e. size of max_sized element in output[] 
            }
        }
        return maxLen;
    }
};
