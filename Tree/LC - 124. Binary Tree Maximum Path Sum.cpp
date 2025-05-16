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
    int maxSum=INT_MIN;
    int maxPathSum(TreeNode* root) 
    {
        dfs(root);
        return maxSum; 
    }
    int dfs(TreeNode* node)
    {
        if(!node)
            return 0;

        int lst=max(0,dfs(node->left));
        int rst=max(0,dfs(node->right));

        maxSum=max(maxSum,node->val+lst+rst);

        return node->val+max(lst,rst);
    }
};
