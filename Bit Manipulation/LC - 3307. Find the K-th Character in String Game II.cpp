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
