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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        unordered_map<int,int> inorderIdx;
        //from inoreder we only need index of where the node will be inorder
        for(int i=0 ; i<inorder.size() ; ++i)
        {
            inorderIdx[inorder[i]]=i;
        }
        int preorderIdx=0;
        return addnode(inorderIdx, preorderIdx, preorder, 0/*left*/, inorder.size()-1);
    }
private:
    TreeNode* addnode(unordered_map<int,int> &inorderIdx, int &preorderIdx, vector<int> &preorder, int left, int right)
    {
        if(left>right)//left has crossed right
            return nullptr;

        //get root from preorder
        int rootVal=preorder[preorderIdx];
        //increment for next iteration
        preorderIdx++;
        //add the node
        TreeNode* root=new TreeNode(rootVal);
        //Use hashmap to find the root’s index in inorder.
        int rootIndex=inorderIdx[rootVal];

        //In inorder:
        //Everything to the left of that root is the left subtree,
        root->left=addnode(inorderIdx, preorderIdx, preorder, left, rootIndex-1/*right*/);//go till left of root
        //And everything to the right is the right subtree.
        root->right=addnode(inorderIdx, preorderIdx, preorder, rootIndex+1, right);//go till left of root

        return root;//return root of current subtree
    }
};
