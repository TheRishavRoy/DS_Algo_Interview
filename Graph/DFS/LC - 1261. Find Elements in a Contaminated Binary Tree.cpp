/*this is a Depth-First Search (DFS) traversal. Specifically, it's a preorder DFS because:

It processes the current node first (recoveredValues.insert(node->val);).
Then it recursively traverses the left subtree (recoverTree(node->left);).
Finally, it recursively traverses the right subtree (recoverTree(node->right);).*/

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
class FindElements {
public:
    // Constructor: Recovers a tree with values changed by the constructor.
    explicit FindElements(TreeNode* root) {
        root->val = 0;//starting the root node initialization to 0
        recoverTree(root);//start recovering. Called recoverTree(root); inside the constructor. The tree recovery process is initiated from the constructor
    }

    // Checks if a value exists in the recovered tree.
    bool find(int target) {
        return recoveredValues.count(target) > 0;
    }

private:
    unordered_set<int> recoveredValues; // Stores the recovered values in the tree.

    // Recursive function to recover the tree.
    void recoverTree(TreeNode* node) 
    {
        if (!node) 
            return;

        // Store the recovered value in the hash set.
        recoveredValues.insert(node->val);

        // If the left child exists, set its value and recover its subtree.
        if (node->left) 
        {
            node->left->val = node->val * 2 + 1;
            recoverTree(node->left);
        }

        // If the right child exists, set its value and recover its subtree.
        if (node->right) 
        {
            node->right->val = node->val * 2 + 2;
            recoverTree(node->right);
        }
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
