class Solution {
public:

    long long findCountSmallest(vector<int>& nums1, vector<int>& nums2, long long midProduct) 
    {
        long long productsCount = 0;

        int n = nums2.size();//fix a place in nums1 and apply binary search on nums2

        for(int i = 0; i < nums1.size(); i++) 
        {
            if(nums1[i] >= 0) //if nums1[i] is +ve then product increases from left to right from here onwards.(since nums1 & nums2 already sorted) 
            {
                //You perform binary search to find the rightmost index j such that:
                //nums1[i] * nums2[j] <= midProduct
                //All elements from 0 to j in nums2 give valid products with nums1[i].
                int l = 0;
                int r = n-1;
                int m = -1; //invalid index on left hand side. I haven't found any valid index yet. If no such product exists in nums2, m stays at -1, and no pairs are counted for this nums1[i]

                while(l <= r) 
                {
                    int mid = l + (r-l)/2;
                    long long product = 1LL * nums1[i] * nums2[mid];

                    if(product <= midProduct) 
                    {
                        m = mid;
                        l = mid+1;//Then, you move the left pointer right (l = mid + 1) to see if there's an even higher valid index.
                    } 
                    else 
                    {
                        r = mid-1;
                    }
                }
                productsCount += (m+1); //there are m+1 indices, they are at positions: 0, 1, 2, ..., m
            } 
            else //Multiplying a negative number with elements of nums2 reverses the order.
            {                
                //Smaller nums2[j] means a larger product in the negative range.
                //So you want the leftmost index j such that:
                //nums1[i] * nums2[j] <= midProduct
                //Valid indices are from j to the end of nums2.
                int l = 0;
                int r = n-1;
                int m = n; //invalid index on the right hand side

                while(l <= r) 
                {
                    int mid = l + (r-l)/2;
                    long long product = 1LL * nums1[i] * nums2[mid];

                    if(product <= midProduct) 
                    {
                        //If product <= midProduct, update m = mid, then move right pointer left (r = mid - 1).
                        m = mid;
                        r = mid-1;
                    } 
                    else 
                    {
                        l = mid+1;//Otherwise, the product is too large (less negative), so move left pointer right (l = mid + 1).
                    }
                }                                                    
                productsCount += (n - m);//Count all values from position m to n - 1
            }
        }
        return productsCount;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long result = 0;

        long long left = -1e10; //min product possible as per constraints in the question
        long long right = 1e10; //max product possible 

        while(left <= right) 
        {
            long long midProduct = left + (right-left)/2;

            //check if this is kth smallest or not

            long long countSmallest = findCountSmallest(nums1, nums2, midProduct);

            if(countSmallest >= k) 
            {
                result = midProduct;
                right = midProduct-1;//its still >=k we might find k in further iteration
                //else loop will terminate with mid=k when right<left(we get kth smallest prod)
            } 
            else 
            {
                left = midProduct+1;//we are still in <k so search in higher bracket
            }
        }
        return result;
    }
};

