class Solution {
public:
    int longestPalindrome(string s) {
        int ans=0;
        vector<int>count(128);
        for(char c:s){
            ++count[c];
        }

        bool odd=false;

        for(int freq: count){
            ans+=freq%2==0?freq:freq-1;
            if(freq&1){
                odd=true;
            }
        }

        return ans+odd;
    }
};