class Solution {
public:
    int f(int row,int col,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){
        int maxi=0;

        if(dp[row][col]!=-1) return dp[row][col];
        for(int dir=-1; dir<=1; dir++){
            int newR=row+dir;
            int newC=col+1;

            if(newR>=0 && newR<m && newC>=0 && newC<n && grid[row][col]<grid[newR][newC]){
                int steps=1+f(newR,newC,n,m,grid,dp);
                maxi=max(maxi,steps);
            }
        }
        return dp[row][col]=maxi;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans=0;
        for(int i=0; i<m; ++i){
            int currMove=f(i,0,n,m,grid,dp);
            ans=max(ans,currMove);
        }
        return ans;
    }
};