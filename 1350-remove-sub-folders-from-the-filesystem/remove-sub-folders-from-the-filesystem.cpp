class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string>st(begin(folder),end(folder));
        vector<string>result;
        for(string currFolder: folder){
            string tempFolder=currFolder;
            bool found=false;
            while(!currFolder.empty()){
                size_t pos=currFolder.find_last_of('/');
                currFolder=currFolder.substr(0,pos);
                if(st.find(currFolder)!=st.end()){
                    found=true;
                    break;
                }
            }
            if(!found){
                result.push_back(tempFolder);
            }
        }
        return result;
    }
};