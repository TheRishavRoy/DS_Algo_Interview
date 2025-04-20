class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        unordered_map<int,int> inorderIdx;
        for(int i=0 ; i<inorder.size() ; ++i)
        {
            inorderIdx[inorder[i]]=i;//we need to keep track of index of each node in inorder traversal
        }
        int postorderIdx = postorder.size() - 1;//we start from the root, root is in the end of postorder traversal

        return addnode(inorderIdx, postorderIdx, postorder, 0, inorder.size() - 1);  //start adding nodes
    }

private:
    TreeNode* addnode(unordered_map<int,int>& inorderIdx, int &postorderIdx, vector<int>& postorder, int left, int right)
    {
        if(left > right)//if left index has crossed right index
            return nullptr;//no more nodes left to process tree path has ended

        int rootVal = postorder[postorderIdx--];//get the root->val of current subtree
        TreeNode* root = new TreeNode(rootVal);//add node with rootVal to the tree

        int rootValIdx = inorderIdx[rootVal];//get index of current root from inorder

        // Build right subtree first (important for postorder!) left,right,root... so we are going from behind
        //adjust left and right limits accordingly lst...root...rst
        root->right = addnode(inorderIdx, postorderIdx, postorder, rootValIdx + 1, right);//call for LST for evrything left of root node
        root->left  = addnode(inorderIdx, postorderIdx, postorder, left, rootValIdx - 1);//call RST for everything right of root node

        return root;
    }
};
