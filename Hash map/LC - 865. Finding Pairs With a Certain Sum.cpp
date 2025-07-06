class FindSumPairs {
public:
    vector<int> nums1, nums2;//declare globle variable as arr1 and arr2 will not be accessible everywhere
    unordered_map<int, int> freqMap; // Keeps frequency of elements in nums2

    FindSumPairs(vector<int>& arr1, vector<int>& arr2) 
    {
        nums1 = arr1;//initialise global variables
        nums2 = arr2;

        for (int num : nums2) //we iterate over nums1 later so we only require map of nums2
        {
            ++freqMap[num];//update freq of each nums2[i]
        }
    }

    void add(int index, int val) 
    {
        // Update frequency map

        //as element at this index will now change:
        --freqMap[nums2[index]];

        //update the element at index
        nums2[index] += val;

        //update new frequency at index
        ++freqMap[nums2[index]];
    }

    int count(int tot) 
    {
        int totCount = 0;
        for (int num : nums1) //since nums1 does not get updated by function add(), we expect it to be shorter. So we iterate over nums1
        {
            int complement = tot - num;//find "nums2[i]"" needed for total of "tot"
            if (freqMap.count(complement)) //if it exists in map
            {
                totCount += freqMap[complement];//add its freq to total because freq many pairs can be made with nums1
            }
        }
        return totCount;
    }
};
