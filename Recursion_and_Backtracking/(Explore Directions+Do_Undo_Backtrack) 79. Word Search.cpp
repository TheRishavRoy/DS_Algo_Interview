class Solution {
public:
    int l, m, n;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};//to explore all the directions
    bool find(vector<vector<char>>& board, int i, int j, string &word, int idx) 
    {
        if(idx >= l)//if all letters in word found idx value this time would be gretter than lenth of word this time
            return true;//return word found to calling function
        
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx])//if out of bound or letters on board not match with letter of word
            return false;
        
        char temp = board[i][j];//store in temp temporarily then change it back during backtracking
        board[i][j] = '$';//replace with $(some symbol) so that we don't explore the same character more than once
        
        for(auto& dir : directions)//explore in all the direction 
        {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            
            if(find(board, i_, j_, word, idx+1))//now search for next letter in word
                return true;
        }
        
        board[i][j] = temp;//on back tracking change it back
        
        return false;//if letter not matched return false
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        m = board.size();//row
        n = board[0].size();//col
        l = word.length();//word length
        if(m*n < l)//if word is too long
            return false;
        
        for(int i = 0; i<m; i++) 
        {
            for(int j = 0; j<n; j++) 
            {
                if(board[i][j] == word[0] && find(board, i, j, word, 0))//if we find starting letter and we found the word as whole return true for found 
                {
                    return true;
                }
            }
        }        
        return false;//if not found
    }
};
