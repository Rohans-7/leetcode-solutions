class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n);
        vector<int> dp(n + 1, 1);
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; ++i){
            hash[i]=i;
            for(int prev=0; prev<i; ++prev){
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
        }

        int ans = -1;
        int lastInd = -1;
        for(int i=0; i<n; ++i){
            if(dp[i]>ans){
                ans=dp[i];
                lastInd=i;
            }
        }

        vector<int> res;
        res.push_back(nums[lastInd]);
        while(hash[lastInd]!=lastInd){
            lastInd=hash[lastInd];
            res.push_back(nums[lastInd]);
        }

        return res;
    }
};