//=============================using map=================================
class Solution {
public:
    bool divideArray(vector<int>& nums) 
    {
        unordered_map<int,int> countOfUniqueNum;
        for(int &num:nums)
        {
            countOfUniqueNum[num]++;
        }
        for(int &num:nums)
        {
            if(countOfUniqueNum[num]%2 != 0)
                return false;
        }
        return true;
    }
};

//==================================== using map && iterator over map======================
class Solution {
public:
    bool divideArray(vector<int>& nums) 
    {
        unordered_map<int,int> countOfUniqueNum;
        for(int &num:nums)
        {
            countOfUniqueNum[num]++;
        }
        for(auto &it:countOfUniqueNum)
        {
            if(it.second%2 != 0)//it.second is the value of {key,value} pair
                return false;
        }
        return true;
    }
};
