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
    std::vector<int> inorderTraversal(TreeNode* root)
    {
        std::vector<int> nodeVals;
        TreeNode* cur = root;
        TreeNode* LSTpointer = nullptr;

        while (cur)
        {
            if (cur->left)
            {
                LSTpointer = cur->left; // Catch hold of left child
                
                // Go to the rightmost node of the left child
                while (LSTpointer->right && LSTpointer->right != cur)
                {
                    LSTpointer = LSTpointer->right; // Keep going
                }

                if (LSTpointer->right == nullptr)
                {
                    LSTpointer->right = cur; // Make rightmost node of left child point to root
                    cur = cur->left; // Move current to left child for further processing
                }
                else
                {
                    LSTpointer->right = nullptr; // Remove the temporary link
                    nodeVals.push_back(cur->val); // Print the node value
                    cur = cur->right; // Move to right child
                }
            }
            else
            {
                nodeVals.push_back(cur->val); // Print the node value
                cur = cur->right; // Move to right child (because left child doesn't exist)
            }
        }

        return nodeVals;
    }
};
