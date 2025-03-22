/*
Description:
============
You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.
You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.
Note that two recipes may contain each other in their ingredients.
*/

/*
Approach:
=========
solve this problem using topological sorting (Kahn’s Algorithm). The idea is:

-Maintain a set of supplies that tracks available ingredients.

-Use an adjacency list (graph) to track which recipes depend on which ingredients.

-Maintain an in-degree count to track how many ingredients are missing for each recipe.

-Use a queue to process recipes where all ingredients are available.

--------------------------------------------------------------------------------------------------------------------
Time Complexity Analysis:
==========================
Building the graph: 
O(R+I), where : R is the number of recipes and I is the total number of ingredients.

Processing recipes in topological order: 
O(R+I).

Total Complexity: 
O(R+I).
*/
class Solution
{
public: 
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        vector<string> result;
        unordered_set<string> supplySet(supplies.begin(), supplies.end()); // Track available ingredients
        unordered_map<string, int> inDegree; // Count missing ingredients for each recipe
        unordered_map<string, vector<string>> dependency; // Recipe dependency graph
        queue<string> q;

        // Step 1: Build inDegree and dependency graph
        for (int i = 0; i < recipes.size(); ++i)
        {
            inDegree[recipes[i]] = ingredients[i].size(); // Track required ingredients
            for (string &ingredient : ingredients[i])
            {
                if (!supplySet.count(ingredient)) // If ingredient is not available initially
                {
                    dependency[ingredient].push_back(recipes[i]); // Recipe depends on this ingredient
                }
                else
                {
                    inDegree[recipes[i]]--; // Reduce missing ingredient count
                }
            }
            if (inDegree[recipes[i]] == 0)
            {
                supplySet.insert(recipes[i]); // Recipe is now available
                q.push(recipes[i]);
            }
        }

        // Step 2: Process recipes in topological order
        while (!q.empty())
        {
            string curr = q.front();
            q.pop();
            result.push_back(curr); // We can prepare this recipe

            for (string &dependentReciepe : dependency[curr])
            {
                if (--inDegree[dependentReciepe] == 0) // If all required ingredients are available
                {
                    q.push(dependentReciepe);
                    supplySet.insert(dependentReciepe); // Add new recipe to available supplies
                }
            }
        }
        return result;
    }
};
