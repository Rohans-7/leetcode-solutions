class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp,int m,int n){
        if(i>=m || j>=n) return 0;
        if(matrix[i][j]==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left=solve(i,j+1,matrix,dp,m,n);
        int right=solve(i+1,j+1,matrix,dp,m,n);
        int dig=solve(i+1,j,matrix,dp,m,n);

        return dp[i][j]=1+min({left,right,dig});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();

        int result=0;
        int n=matrix[0].size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(matrix[i][j]==1){
                    result+=solve(i,j,matrix,dp,m,n);
                }
            }
        }

        return result;
    }
};