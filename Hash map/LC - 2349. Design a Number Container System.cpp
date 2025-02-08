class NumberContainers {
public:
    unordered_map<int,int> indexToNumber;//for a given index we may have to update number
    unordered_map<int, set<int>> numberToIndices;  // Maps number -> sorted indices (to find the smallest index easily)
    
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        //we have to handle the case where the old number is now invalid
        if (indexToNumber.count(index)) //if index was already associated to a number
        {
            int oldNumber = indexToNumber[index];//we have to remove the old number from our numberToIndices mapping

            numberToIndices[oldNumber].erase(index);// Remove the old index from its set of indices. 
            //the oldnumber no longer will have this index to its set of indices.

            if (numberToIndices[oldNumber].empty())//if no more index for this number 
            {
                numberToIndices.erase(oldNumber);  // Remove the key oldnumber from the set if no indices remain
            }
        }
        indexToNumber[index]=number;//either add new or overwrite

        numberToIndices[number].insert(index);  // Add the index to the new number's set
    }
    
    int find(int number) 
    {
        if (numberToIndices.count(number) 
        && !numberToIndices[number].empty()) //if the entry for key=number exists. AND its set of indices is non-empty
        {
            return *numberToIndices[number].begin();  // Return the pointer to start of set of indices i.e. smallest index
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
