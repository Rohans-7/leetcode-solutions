class Solution {
public:
    bool isEqual(vector<int>&nums,int ind,int target,vector<vector<int>>&dp){
        if(target==0){
            return true;
        }
        if(ind==0){
            return nums[0]==target;
        }
        
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        
        bool notTake=isEqual(nums,ind-1,target,dp);
        bool take=false;
        if(target>=nums[ind]){
            take=isEqual(nums,ind-1,target-nums[ind],dp);
        }
        
        return dp[ind][target]=(take||notTake);
        
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int N=nums.size();
        for(int i=0; i<N; i++){
            sum+=nums[i];
        }
        
        if(sum&1){
            return 0;
        }
        
        vector<vector<int>>dp(N,vector<int>(sum/2+1,-1));
        
        return isEqual(nums,N-1,sum/2,dp);
    }
};