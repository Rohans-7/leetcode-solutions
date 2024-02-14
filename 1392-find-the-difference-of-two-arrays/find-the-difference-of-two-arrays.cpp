class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums1Abs,nums2Abs;

        set<int>s1,s2;

        for(int i=0; i<nums1.size(); i++){
            s1.insert(nums1[i]);
        }

        for(int i=0; i<nums2.size(); i++){
            s2.insert(nums2[i]);
        }

        for(auto it:s1){
            if(s2.find(it)==s2.end()){
                nums1Abs.push_back(it);
            }
        }

        for(auto it:s2){
            if(s1.find(it)==s1.end()){
                nums2Abs.push_back(it);
            }
        }

        return {nums1Abs,nums2Abs};
    }
};