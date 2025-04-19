/*Approach 1:
===========
1. Simple recursion call
2. Keep Subtracting node->val from targetSum before calling LST and RST
3. Base case: If we reach leaf, check if node->val == (what ever is remaining of the targetSum )
   (OR) check if (targetSum - node->val) == 0

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(!root)
            return false;

        if(root->left==nullptr && root->right==nullptr)//if the node is leaf, we have reached the end of the path
        {
            return root->val==targetSum;//checking if root->val is all thats left to be subtracted
        }
        //keep subtracting current node val while making recursive calls
        return hasPathSum(root->left,targetSum-(root->val))||hasPathSum(root->right,targetSum-(root->val));    
    }
};
//======================================================================================================================
/*Approach 2:
1. Call DFS on the root node,cuurentSum,targetSum
2. In helper function keep calculating currentSum
3. Recursively call LST and RST
4. If we reached leaf, check if currentSum==targetSum
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root,0,targetSum);
    }
private:
    bool dfs(TreeNode* node, int currentSum, int targetSum)
    {
        if(!node)
            return false;//we have reached the end of recursive path, without finding our tagetSum
        
        currentSum+=node->val;

        if(node->left==nullptr && node->right==nullptr)//reached the leaf
        {
            if(currentSum==targetSum)
                return true;
        }

        return dfs(node->left,currentSum,targetSum)||dfs(node->right,currentSum,targetSum);//we might find targetSum in either LST path or RST path
    }
};
