/* 
The whole point of Morris Traversal Algorithm for in-order traversal is **“Eliminating the need of returning back to root.”**

We know for sure that in in-order traversal, the root of the tree is processed **only after completely processing the left subtree**.  
Therefore, we move the root to the right of the left subtree **until we find that there is a left tree**.  
If we continuously follow this process, we come to a condition where our tree **becomes a right-skewed tree!**  
Thus, we can conclude that **Morris Traversal is all about converting a binary tree into a right-skewed tree.**

### **Algorithm Steps:**
1. Keep hold of `current_root`, and check if the **left child exists**.
2. If Yes, go to the **rightmost node of the left child** and make it point to `current_root`.
3. Make `current_root`'s left `nullptr`.
4. If No, **print the value of the node** and move to **right child**.
5. Follow this **until `current_root` exists**.
====================================================================================================================================*/

#include <iostream>
#include <vector>

struct TreeNode
{
    int val; // Fix: 'val' should be an int, not a pointer
    TreeNode* left;
    TreeNode* right;
    
    TreeNode() : val(0), left(nullptr), right(nullptr) {} // Fix: Proper constructor initialization
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* leftPtr, TreeNode* rightPtr) : val(x), left(leftPtr), right(rightPtr) {}
};

class MorrisTraversal
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {

        vector<int> v;
        TreeNode *cur = root;
        TreeNode *LST = NULL;
        TreeNode *temp = NULL;

      // run algorithm until root exists
        while (cur)
        {
            // if left child exists
            if (cur->left)
            {
                LST=cur->left; // catch hold of left child
           
                while(LST->right) // go to right most node of left child
                    LST=LST->right;
        
            LST->right=cur; // make it point to the root

            temp=cur;//so we don't lose the ptr
            cur=cur->left;//move cur for further iteration
            temp->left=NULL; // make left of root null
        }
        else
        {
            v.push_back(cur->val); // print the node value
            cur=cur->right; // move to right child (because left child doesn't exist)
        }
    }
    return v;
    }
};
