class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int n=emails.size();
        set<string>s;
        for(int i=0; i<n; i++){
            string s1=emails[i];

            string back="";
            int j=s1.length()-1;
            while(s1[j]!='@'){
                back+=s1[j];
                j--;
            }
            reverse(back.begin(),back.end());

            int k=0;

            string local="";

            while(s1[k]!='@'){
                if(s1[k]=='+'){
                    break;
                }
                else if(s1[k]!='.'){
                    local+=s1[k];
                    k++;
                }
                else{
                    k++;
                }
            }

            local=local+'@'+back;
            s.insert(local);
        }

        return s.size();
    }
};