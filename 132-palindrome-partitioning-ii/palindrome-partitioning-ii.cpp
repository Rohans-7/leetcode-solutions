class Solution {
public:
    int isPal(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]) return 0;
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    int f(int i,int n,string s){
        if(i>=n) return 0;
        string temp="";
        int minC=INT_MAX;
        for(int j=i; j<n; ++j){
            temp+=s[i];
            if(isPal(i,j,s)){
                int cost=1+f(j+1,n,s);
                minC=min(minC,cost);
            }
        }

        return minC;
    }
    int minCut(string s) {
        int n=s.length();
        vector<int>dp(n+1,0);

        for(int ind=n-1; ind>=0; --ind){
            int minC=INT_MAX;
            for(int j=ind; j<n; ++j){
                if(isPal(ind,j,s)){
                    int cost=1+dp[j+1];
                    minC=min(minC,cost);
                }
            }
            dp[ind]=minC;
        }
        return dp[0]-1;
        
        // return f(0,s.length(),s)-1;
    }
};