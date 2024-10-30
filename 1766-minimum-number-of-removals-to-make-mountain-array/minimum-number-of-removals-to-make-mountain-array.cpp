class Solution {
public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int>dp1(n+1,1);
        vector<int>dp2(n+1,1);
        int maxi=0;
        for(int i=0; i<n; ++i){
            for(int prev=0; prev<i; ++prev){
                if(nums[prev]<nums[i]){
                    dp1[i]=max(dp1[i],1+dp1[prev]);
                }
            }
        }
        for(int i=n-1; i>=0; --i){
            for(int prev=n-1; prev>i; --prev){
                if(nums[prev]<nums[i]){
                    dp2[i]=max(dp2[i],1+dp2[prev]);
                }
            }
        }
        
        for(int i=0; i<n; ++i){
            if(dp1[i]>1 && dp2[i]>1) maxi=max(maxi,dp1[i]+dp2[i]-1);
        }
        
        return maxi;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        return n-LongestBitonicSequence(n,nums);
    }
};