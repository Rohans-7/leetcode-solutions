class Solution {
public:
    int ans=0;
    int countPairs(int ind, int n,int curr, vector<int>&nums, int mx){
        if(ind==n){
            if(curr==mx){
                return 1;
            }
            return 0;
        }
        int left=countPairs(ind+1, n , curr | nums[ind], nums,mx);
        int right=countPairs(ind+1, n, curr, nums, mx);
        return left+right;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr=0;
        for(int i=0; i<nums.size(); ++i){
            maxOr=maxOr | nums[i];
        }
        return countPairs(0,nums.size(),0,nums,maxOr);
    

    }
};