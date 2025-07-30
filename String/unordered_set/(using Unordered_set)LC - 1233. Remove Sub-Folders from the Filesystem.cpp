class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        unordered_set<string> st(folder.begin(),folder.end());// it will make searching easy
        vector<string> result;
        bool isSubFolder;
        for(string& currFolder : folder) 
        {
            isSubFolder = false;
            string tempFolder = currFolder;//we keep the original folder so that we may push it into result
            while(!currFolder.empty()) //we will keep taking its substring
            {
                size_t position = currFolder.find_last_of('/');//size_t :  an unsigned integer data type.
                //It's a type which is used to represent the size of objects in bytes and is therefore used as the return type by the sizeof operator
                
                //position will give us length of substring from i=0 to last'/' i.e. parent directory

                currFolder = currFolder.substr(0, position);//strip path down to the parrent path

                if(st.count(currFolder)) //parent path already present
                {
                    //it means currFolder is a sub-folder
                    isSubFolder = true;
                    break;
                }
            }

            if(!isSubFolder) 
            {
                result.push_back(tempFolder);//push only folders that are not sub-folder of some other folder
            }

        }

        return result;
    }
};
