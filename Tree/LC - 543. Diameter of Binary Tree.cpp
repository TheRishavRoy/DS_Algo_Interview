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
class Solution 
{
public:
    int getMaxDiameter(TreeNode* node, int &diameter)
    {
        if(node==nullptr)
            return 0;

        int LeftDiameter=getMaxDiameter(node->left,diameter);
        int RightDiameter=getMaxDiameter(node->right,diameter);

        diameter=max(diameter,LeftDiameter+RightDiameter);//LeftDiameter+RightDiameter is the diameter at that specific node
        return max(LeftDiameter,RightDiameter)+1;//we actually return the height of the current subtree so the parent node can compute its own diameter. It helps fuel the recursive computation but is not the diameter itself.


        /*
            - Height	Longest path from node to a leaf	Returned by recursion to parent nodes
            - Diameter	Longest path between any two nodes	Computed as leftHeight + rightHeight at each node
        */
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int diameter=0;
        getMaxDiameter(root,diameter);
        return diameter;
    }
};
