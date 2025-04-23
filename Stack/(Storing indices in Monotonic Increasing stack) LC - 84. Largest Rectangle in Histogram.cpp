/*
A Monotonic stack is a stack where the elements are maintained in either increasing or decreasing order. It’s not about the actual values you push, but how they relate to previous ones.

Monotonically Increasing Stack:
- You pop when a smaller value comes in.
- Useful for finding next smaller elements.
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*
        We use a monotonic increasing stack to keep track of indices of bars. 
        The idea is to determine the next smaller element on both the left and right for every bar. 
        With those, we can calculate the maximum rectangle that each bar can be part of.
        */

        /*
        1. For each heights[i], we find the first bar to the left and right that is shorter than heights[i].
        2. Once we have that, the width of the rectangle with height heights[i] is (right - left - 1).
        3. Area = height * width.
        */

        int n=heights.size();
        stack<int> st;
        int maxArea=0;

        for(int i=0 ; i<=n ; ++i)
        {
            /*By setting curHeight = 0 at i == n, you're forcing the algorithm to:
                - Pop all the remaining bars from the stack.
                - Compute any pending area calculations that haven't been handled yet.*/

            int currentHeight=(i==n)?0:heights[i];

            while(!st.empty() && currentHeight<heights[st.top()])//we cannot stretch rectangle upto current height, we start going back
            {
                //each bar gets a chance to form a rectangle using its own height.
                //therefore we take height[st.top()] and width=1(since !st.empty())
                //now if there is a samaller bar to the left height will be updated to a samller height[st.top()] but now width becomes 2 and we calculate MaxArea again 
                int height = heights[st.top()];
                st.pop();

                //If the stack is empty after popping, it means the popped bar can stretch from the beginning of the array (index 0) to index i → so width = i.
                int width = st.empty() ? i : i - st.top() - 1;

                maxArea = max(maxArea, height * width);
            }

            //if currentHeight is greater than st.top() we simply continue pushing.
            //otherwise we push index anyway
            st.push(i);
        }
        return maxArea;
    }
};
