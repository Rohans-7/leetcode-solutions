class Solution {
public:
    int f(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=1e9;
        for(int ind=i; ind<=j; ++ind){
            int cost=cuts[j+1]-cuts[i-1]+f(i,ind-1,cuts,dp)+f(ind+1,j,cuts,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        m=m-2;
        vector<vector<int>>dp(m+2,vector<int>(m+2,0));

        // return f(1,m-2,cuts,dp);
        for(int i=m; i>=1; --i){
            int mini=1e9;
            for(int j=1; j<=m; ++j){
                if(i>j) continue;
                int mini=INT_MAX;
                for(int ind=i; ind<=j; ++ind){
                    int ans=cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
                    mini=min(mini,ans);
                }
                dp[i][j]=mini;
            }
        }

        return dp[1][m];
    }
};