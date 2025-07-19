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
    int isBalanced(TreeNode* root, bool &result)//since height is involved need to keep it int
    {
        // base case: tree is empty or not balanced
        if (root == nullptr || !result) 
        {
            return 0;//since no calculation is required and result=true already
        }

        // get the height of the left subtree
        int left_height = isBalanced(root->left, result);

        // get the height of the right subtree
        int right_height = isBalanced(root->right, result);

        // tree is unbalanced if the absolute difference between the height of
        // its left and right subtree is more than 1
        if (abs(left_height - right_height) > 1) 
        {
            result = false;//since unbalanced
        }
 
        // return height of subtree rooted at the current node
        return max(left_height, right_height) + 1;//height keeps calculating at each node level
    }
    bool isBalanced(TreeNode* root) {
        bool result = true;
        isBalanced(root, result);//would keep calculating balnace/imabalance at each node
 
        return result;//return the result
    }
};
