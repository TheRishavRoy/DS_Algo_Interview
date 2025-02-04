struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(): val(0), left(nullptr), right(nullptr){}
  TreeNode(int x): val(x), left(nullptr), right(nullptr){}
  TreeNode(int x, TreeNode *Left, TreeNode *Right): val(x), left(nullptr), right(nullptr){}
};
class Solution
{
public:  
  bool isSameTree(TreeNode *p, TreeNode *q)
  {
    if(p==NULL && q==NULL)
        return true;
    if(p==NULL || q==NULL || p->val!=q->val)//if either one false or values are not equal
        return false;
    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);//call recursively for LST and RST for both tree 
  }
};
