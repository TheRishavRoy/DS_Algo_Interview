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
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);  // Use LONG_MIN/MAX to prevent overflow
        //at the start (root node) limits are LONG_MIN, LONG_MAX
    }

private:
    bool dfs(TreeNode* node, long minVal, long maxVal) 
    {
        if (!node) 
            return true;

        if (node->val <= minVal || node->val >= maxVal)//== case is also invalid so we return false
            return false;

        //call LST and RST recursively keeping in mind current limits are minVal and maxVal
        return dfs(node->left, minVal, node->val) &&
               dfs(node->right, node->val, maxVal);
    }
};
