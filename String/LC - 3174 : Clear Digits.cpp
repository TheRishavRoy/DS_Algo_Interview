class Solution {
public:
    std::string clearDigits(std::string s) {
        int n = s.size();
        if (n == 0)
            return "";

        stack<int> indices;

        for (int i = 0; i < s.size(); i++) 
        {
            if (s[i] >= 'a' && s[i] <= 'z') 
            {  // Corrected ASCII check
                indices.push(i);
            } 
            else if (s[i] >= '0' && s[i] <= '9') 
            {  
                // Digit check
                if (!indices.empty()) 
                {
                    int idx = indices.top();
                    indices.pop();

                    s.erase(s.begin() + i);  // Remove digit
                    s.erase(s.begin() + idx);  // Remove corresponding letter

                    i -= 2;  // Adjust index to avoid skipping characters
                }
            }
        }
        return s;
    }
};
