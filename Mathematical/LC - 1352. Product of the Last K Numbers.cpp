// key concept here is how to calculate the product of the last k numbers without multiplying again and again from scratch to do this :
//  product of the last k numbers = (product of all)/( product of the first (size - k) elements in the array )
class ProductOfNumbers 
{
public:
    // Stores the prefix products; prefix_products[i] is the product of all numbers up to index i
    std::vector<int> prefix_products;
    ProductOfNumbers() 
    {
        // Initialize with 1, to handle the product calculation
        prefix_products.push_back(1);
    }

    void add(int num) 
    {
        // If number is zero, reset the products list as any subsequent product will be 0
        if (num == 0) 
        {
            prefix_products.clear();
            prefix_products.push_back(1);//again pushing 1 for handling multiplications
        } 
        else 
        {
            // Otherwise, calculate the new product and add to the list
            int new_product = prefix_products.back() * num;
            prefix_products.push_back(new_product);
        }
    }

    int getProduct(int k) 
    {
        int size = prefix_products.size();
        
        if (size <= k) // If k is greater or equal to the size of the list, return 0 since there are not enough elements
        {
            return 0;
        } 
        else 
        {
            // Otherwise, return the product of the last k numbers
            // which is == (product of all)/( product of the first (size - k) elements in the array )
            int product = prefix_products.back() / prefix_products[size - k - 1];
            return product;
        }
    }

//private:
    // Stores the prefix products; prefix_products[i] is the product of all numbers up to index i
    //std::vector<int> prefix_products;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
