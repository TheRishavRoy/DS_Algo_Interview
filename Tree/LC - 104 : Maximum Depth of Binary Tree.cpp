struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode():val(0),left(nullptr),right(nullptr){}
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
  TreeNode(int x, TreeNode *left, TreeNode *right):val(x),left(left),right(right){}
};
class Solution
{
public:
  int maxDepth(TreeNode *root)
  {
      if(!root)
        return 0;
    int LST=maxDepth(root->left);
    int RST=maxDepth(root->right);

    return 1+(LST>RST?LST:RST);//return count of this node + recursively returned value
  }
};
