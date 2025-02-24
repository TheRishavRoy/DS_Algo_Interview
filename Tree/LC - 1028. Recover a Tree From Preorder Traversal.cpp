/*
1. The idea is to use an iterator i to parce input string AND a local variable to calculate the depth of current node
2. We use a stack to process the nodes 1 by 1 and find the right parent node.
3. if depth==stack height we need to push current node to left of parent node.
4. while(depth>stack height, we keep popping from stack to reach parent node.
5. attach the current node to right of parent.
6. lastly push current node to the stack

Time Complexity: 
O(N), since we traverse the string once.

Space Complexity: 
O(N), using a stack to maintain the depth hierarchy.
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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> st;
        int i = 0;//to parse input string
        int n = traversal.size();

        while (i < n) 
        {
            int depth = 0;//local depth
            // Count dashes to determine the depth
            while (i < n && traversal[i] == '-') 
            {
                depth++;
                i++;//next indices in the string 
            }

            // Read the node value
            int value = 0;
            while (i < n && isdigit(traversal[i])) 
            {
                value = value * 10 + (traversal[i] - '0');//could be a multidigit number
                i++;//next indices in the string
            }

            TreeNode* node = new TreeNode(value);//keep forming nodes as we have to return the tree

            // If depth equals stack size, it means it's a left child
            //Since we always push the parent before its children, the first child at that depth is always the left child.
            if (depth == st.size()) 
            {
                if (!st.empty()) 
                {
                    st.top()->left = node;
                }
            } 
            else 
            {
                // Otherwise, pop until we find the correct parent
                // we pop to backtrace to the parent
                while (st.size() > depth) 
                {
                    st.pop();
                }
                st.top()->right = node;//then attach the child to right of parent
            }
            st.push(node);//push current node for future processing
        }

        // The root of the tree is the bottom-most element in the stack
        while (st.size() > 1) //get to the root
        {
            st.pop();
        }

        return st.top();//return the root
    }
};
