/*Approach 2: Monotonic decreasing stack

- We push indices of bars onto the stack, maintaining a decreasing height order.
- When we encounter a higher bar, it means we've found the right boundary of a container.
- We then pop from the stack and compute trapped water using the popped bar as the bottom of the container.
- The new top of the stack becomes the left boundary.
*/
class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        stack<int> stk; // Store indices
        int water = 0;

        for (int i = 0; i < n; ++i)
        {
            while(!stk.empty() && height[i]>height[stk.top()])
            {
                int bottom = stk.top();
                stk.pop();

                if(stk.empty())
                {
                    break;//no left boundary
                }

                int left=stk.top();
                int width=i-left-1;//we go backwards(left) from i
                int boundedHeight = min(height[left], height[i]) - height[bottom];//left and i are boundary, bottom is base
                water+=boundedHeight*width;
            }
            stk.push(i);
        }
        return water;            
    }
};
