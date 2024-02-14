class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>m;

        for(int i=0; i<text.length(); i++){
            if(text[i]=='b' || text[i]=='a' || text[i]=='l' || text[i]=='o' || text[i]=='n'){
                m[text[i]]++;
            }
        }

        if(m['b']==0 || m['a']==0 || m['l']==0 || m['o']==0 || m['n']==0){
            return 0;
        }

        int ans=text.length();

        for(auto &i: m){
            if(i.first=='b'){
                ans=min(ans,m['b']);
            }
            if(i.first=='a'){
                ans=min(ans,m['a']);
            }
            if(i.first=='l'){
                ans=min(ans,m['l']/2);
            }
            if(i.first=='o'){
                ans=min(ans,m['o']/2);
            }
            if(i.first=='n'){
                ans=min(ans,m['n']);
            }
        }

        if(m.size()==5){
            return ans;
        }

        return 0;

        
    }
};