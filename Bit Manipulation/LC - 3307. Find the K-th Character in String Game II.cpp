class Solution {
public:
  char kthCharacter(long long k, vector<int>& operations) 
  {
    // Determine how many steps (string doublings) are needed to reach or exceed position k.
    // This is essentially the smallest 'n' such that 2^n ≥ k.
    const int operationsCount = ceil(log2(k));//ceil of log base 2 of k, is the number of operations required 

    int increases = 0;  // This will track how many letter shifts are applied in total.

    // Traverse the transformation steps in reverse.
    // Each operation doubles the string, so we step backward through the "unfolding" process.
    for (int i = operationsCount - 1; i >= 0; --i) 
    {
      // Compute the half size of the string at step i
      const long halfSize = 1L << i;

      // If k lies in the right half of the string, we map it to the left half.
      // We also apply the shift value from operations[i]
      if (k > halfSize) 
      {
        k -= halfSize;  // Reflect k into the left half of the string
        increases += operations[i];  // Apply corresponding letter shift
      }
      // If k ≤ halfSize, it remains in the left half — no shift applied this step
    }

    // Start from 'a', apply all collected shifts (modulo 26 to wrap around alphabet)
    return 'a' + increases % 26;
  }
};

/*
Example:
Input k = 5 operations = [0,0,0] Output "a" Expected "a"
============================================================

You determine how many operations are required to cover position k: ceil(log₂(5)) = 3, so we work through 3 steps in reverse.

Step by step:
-------------
Step 2: halfSize = 4 → Since k = 5 > 4(k is in right half of doubling), you subtract 4 => (k = k - 4) = 1; So add operations[2] = 0
Step 1: halfSize = 2 → k = 1 stays in left half; (k = 1 ≤ 2, it’s clearly in the left half, so You leave k unchanged. You don't apply any shift). add 0.
Step 0: halfSize = 1 → k = 1 still stays in left; add 0

Total shift accumulated: 0

Result: 'a' + (0 % 26) = 'a'


Like in step 2 : Because in a string of length 8 (after 3 doublings), the 5th character lies in the right half (positions 5 to 8), which is just a copy of the left half (1 to 4) with a letter shift applied. 
So we reflect position 5 back to position 1 and track that shift.
That reflection step is the key insight here—it lets you avoid actually building the full string while still tracking how the character was transformed.
*/
