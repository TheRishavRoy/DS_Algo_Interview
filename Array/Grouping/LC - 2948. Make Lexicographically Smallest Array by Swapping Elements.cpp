/*(using sorting and grouping using unordered_map*/
/* 
-We group together elements such that every element has a difference of <=limit with atleast one element in the group.
-This way we can sort that group in lexographically
-This will Prevent TLE problem we got in brute force approach
*/
//=====================================================================================================================
/*
Key Concepts:
====================
Sorting for Grouping:
Sorting simplifies the task of grouping, as elements that could belong to the same group will always be contiguous in the sorted array.

Group Mapping:
numToGroup maps each number to its corresponding group, ensuring efficient group lookup.

Efficient Group Access:
groupToList stores the numbers of a group in a list. The lexicographically smallest number is always the first element (.begin()).

Avoiding Duplicates:
By removing the smallest number in the group after it's used (pop_front()), duplicates in the result are prevented.


Time Complexity:
=================
1.Sorting the array: 
O(nlogn)
2.Iterating through the sorted array to form groups: 
O(n)
3.Constructing the result array:
4.Accessing groupToList and removing an element: 
O(1) (amortized for std::list).
5.Overall Complexity: 
O(nlogn), dominated by sorting.

Space complexity: O(n) due to additional vector(to keep nums undisturbed) and the unordered_map used twice
*/
class Solution 
{
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) 
    {
        int n = nums.size();

        vector<int> vec = nums;
        //sort the vec
        sort(begin(vec), end(vec));

        int groupNum = 0;
        unordered_map<int, int> numToGroup;//which number is in which group
        numToGroup[vec[0]] = groupNum;

        unordered_map<int, list<int>> groupToList;//what numbers are in a particular group. represent this in list form
        groupToList[groupNum].push_back(vec[0]); //O(1) at first only vec[0] belongs to groupNum0

        for(int i = 1; i < n; i++)//start from second element and go till last element 
        {
            if(abs(vec[i] - vec[i-1]) > limit) 
            {
                groupNum += 1;//then we put in new group. if it was <= we would skip this part of code and put it in same group
            }

            numToGroup[vec[i]] = groupNum;//update accordingly
            groupToList[groupNum].push_back(vec[i]);//update accordingly
        }
        
        //Build the anwer - Merge the groups
        vector<int> result(n);
        for(int i = 0; i < n; i++) 
        {
            int num = nums[i];
            int group = numToGroup[num];//what is its group number ?
            //smallest available number in this group
            result[i] = *groupToList[group].begin(); //since .begin() gives iterator to the first element in the container(set), 
            //we use derefrence operator *. 
            //The * operator dereferences the iterator returned by .begin() to access the actual value it points to.
            groupToList[group].pop_front();//since this number has been already used so delete this number, 
            //to avoid duplicate elements in result
        }

        return result;
    }
};
