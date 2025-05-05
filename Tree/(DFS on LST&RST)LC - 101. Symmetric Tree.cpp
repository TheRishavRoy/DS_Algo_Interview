/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

                                         1
										/ \
									   2   2
									  /\   /\
									 3  4 4  3
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
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left,root->right);
    }
private:
    bool dfs(TreeNode* leftNode,TreeNode* rightNode)
    {
        if(!leftNode && !rightNode)
            return true;

        if(!leftNode || !rightNode)
            return false;

        if(leftNode->val!=rightNode->val)
            return false;

        return dfs(leftNode->left,rightNode->right)&&dfs(leftNode->right,rightNode->left);
    }
};
