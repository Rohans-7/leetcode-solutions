class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>m;

        for(auto i:arr){
            ++m[i];
        }

        vector<int>res;

        for(auto &[_,c]:m){
            res.push_back(c);
        }

        sort(res.begin(),res.end());
        
        int n=res.size();

        for(int i=0; i<res.size(); i++){
            k-=res[i];
            if(k<0){
                return n-i; 
            }
        }
        return 0;
    }
};