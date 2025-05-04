class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> count(100, 0);
        int res = 0;

        for (auto& d : dominoes) {
            int a = d[0], b = d[1];
            //since a,b nad b,a form a pair that will contribute to the result together,
            //we keep a,b and b,a under same key,value entry in map
            int key = a < b ? a * 10 + b : b * 10 + a;
            
            //Before incrementing the count for the current domino's key, you add the current count of dominoes with the same key to res. This is because any previously encountered domino with the same key forms an equivalent pair with the current domino.
            res += count[key];
            count[key]++;
        }

        return res;
    }
};
