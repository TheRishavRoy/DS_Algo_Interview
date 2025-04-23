/*
TC: O(N)

Insight, thought process:
=========================
- DFS recursively calculates the depth of each subtree.
- If left and right subtree depths are equal, current node is LCA of deepest leaves.
- Else, you propagate the deeper subtree’s LCA upward.

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
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
           return dfs(root).first; 
    }
private:
    pair<TreeNode*,int>dfs(TreeNode* node)
    {
        if(!node)
            return {nullptr,0};

        auto left=dfs(node->left);
        auto right=dfs(node->right);
        /*
        NOTE: we are finding : 
        - The lowest node that connects all deepest leaves.
        - This node might not be present at depth d-1 ; where d is the depth of depest node(leaf)
        - In case of complete binary tree this node will be the Root, Since root is the only node that connects all the deepest leaves
        */
        if(left.second>right.second)
            return {left.first,left.second+1};//we propagate the left leaf upwards since it is deeper
        else if(right.second>left.second)
            return {right.first,right.second+1};
        else//we found LCA if left depth == right depth
            return {node,left.second+1};//either left or right both are correct
    }
};
