class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            string curr=words[i];

            int left=0,right=curr.length()-1;
            int ans=true;

            while(left<right){
                if(curr[left]==curr[right]){
                    left++;
                    right--;
                }
                else{
                    ans=false;
                    break;
                }
            }

            if(ans){
                return curr;
            }
        }
        return "";
    }
};