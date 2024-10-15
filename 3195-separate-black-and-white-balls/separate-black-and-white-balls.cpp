class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        long long cnt = 0;
        for(auto ch: s){
            if(ch=='1'){
                cnt++;
            }
            else{
                ans += cnt;
            }
        }
        return ans;
    }
};