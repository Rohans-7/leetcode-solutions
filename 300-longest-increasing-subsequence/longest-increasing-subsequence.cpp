class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int ind=n-1; ind>=0; --ind){
            for(int pind=ind-1; pind>=-1; --pind){
                int len=dp[ind+1][pind+1];
                if(pind==-1 || nums[ind]>nums[pind]){
                    len=max(len,1+dp[ind+1][ind+1]);
                }
                dp[ind][pind+1]=len;
            }
    
        }
        return dp[0][0];
    }
};