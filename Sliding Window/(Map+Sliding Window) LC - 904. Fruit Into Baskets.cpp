class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        unordered_map<int, int> count;//Used to track the frequency of each fruit type in the window.
        
        //left and right defines the window's boundaries.
        int left = 0, maxFruits = 0;

        for (int right = 0; right < fruits.size(); ++right) 
        {
            count[fruits[right]]++;//add current entry

            //If the map holds more than 2 fruit types, that violates the basket rule.
            //We must try and erase to bring size of count map to == 2
            while (count.size() > 2) //ensures we respect the two-basket constraint. shrink only upto == 2
            {
                count[fruits[left]]--;

                if (count[fruits[left]] == 0)
                    count.erase(fruits[left]);//this helps decrease the size of map to == 2
                
                left++;//move to next index, shrink window
            }

            maxFruits = max(maxFruits, right - left + 1);
        }

        return maxFruits;
    }
};
