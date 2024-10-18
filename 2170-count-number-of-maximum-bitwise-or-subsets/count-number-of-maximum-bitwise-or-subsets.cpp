class Solution {
public:
    int ans=0;
    void countPairs(int ind, int n,int curr, vector<int>&nums, int mx){
        if(ind==n){
            if(curr==mx){
                ans++;
            }
            return;
        }
        countPairs(ind+1, n , curr | nums[ind], nums,mx);
        countPairs(ind+1, n, curr, nums, mx);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr=0;
        for(int i=0; i<nums.size(); ++i){
            maxOr=maxOr | nums[i];
        }
        countPairs(0,nums.size(),0,nums,maxOr);
        return ans;
    

    }
};