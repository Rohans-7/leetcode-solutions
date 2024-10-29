class Solution {
public:
    int f(int ind,int n,int k,vector<int>&num){
        if (ind == n) return 0;

        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;

        for (int j = ind; j < min(ind + k, n); j++) {
            len++;
            maxi = max(maxi, num[j]);
            int sum = len * maxi + f(j + 1, n, k,num);
            maxAns = max(maxAns, sum);
        }

        return maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();

        vector<int>dp(n+1,0);
        dp[n]=0;

        for(int i=n-1; i>=0; --i){
            int len=0;
            int maxi=INT_MIN;
            int maxSum=INT_MIN;
            for(int j=i; j<min(i+k,n); ++j){
                len++;
                maxi=max(maxi,arr[j]);
                int sum=len*maxi+dp[j+1];
                maxSum=max(maxSum,sum);
            }
            dp[i]=maxSum;
        }
        return dp[0];
    }
};