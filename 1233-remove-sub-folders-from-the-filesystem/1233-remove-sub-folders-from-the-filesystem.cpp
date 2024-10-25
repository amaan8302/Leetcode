class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string>st(folder.begin(),folder.end());
        vector<string>res;
        for(string& currFolder:folder)
        {
            bool isSub = 0;
            string temp = currFolder;
            while(!currFolder.empty())
            {
                size_t position = currFolder.find_last_of('/');
                currFolder = currFolder.substr(0,position);
                if(st.find(currFolder)!=st.end())
                {
                    isSub=1;
                    break;
                }
            }
            if(isSub==0)
                res.push_back(temp);
        }
    return res;
    }
};