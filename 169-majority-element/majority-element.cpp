class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        int n=nums.size();

        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }

        for(auto m1:m){
            if(m1.second>n/2){
                return m1.first;
            }
        }

        return -1;
    }
};