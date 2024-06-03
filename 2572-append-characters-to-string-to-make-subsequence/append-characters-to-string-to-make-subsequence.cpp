class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0,j=0;

        int n1=s.length(),n2=t.length();

        while(i<n1 && j<n2){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        int ans=0;

        if(i<n1){
            return 0;
        }

        if(j<n2){
            ans+=(n2-j);
        }

        return ans;
    }
};