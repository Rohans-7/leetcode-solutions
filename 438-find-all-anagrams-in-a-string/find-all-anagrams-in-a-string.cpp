class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> mp;

     //initializing left and right and ans(no of occurrences)
     int i = 0, j =0,ans = 0;
     
     for(auto &v : p){
         mp[v]++;
     }
     
     int size = s.size();
     vector<int>res;
     //window size
     int k = p.size();
     //distinct char in pattern
     int count = mp.size();
     
     while(j < size)
     {
         //Calculation 
         //if current char in map
         if(mp.find(s[j])!=mp.end())
         {
             //decrementing map value so we can know all 
               //chars are ended when it is zero.
             mp[s[j]]--;
             //if no frequency of char then distinct char count decremented.
             if(mp[s[j]]==0){
                 count--;
             }
         }
         //window is not completed
         if(j-i+1 < k)
         {
             //window expansion
             j++;
         }
         else if(j-i+1 == k)
         {
             //all distinct elements are ended in map means anagram matched.
             if(count==0){
                 ans++;
                 res.push_back(i);
             }
             //sliding the window and removing calculation for index i
             if(mp.find(s[i]) != mp.end() )
             {
                //if item in map so we are incrementing
                 mp[s[i]]++;
                 //if it is the first char then distinct char count incremented.
                 if(mp[s[i]] == 1)
                 {
                     count++;
                 }
             }
             //slide
             i++;
             j++;
         }
     }
     return res;
    }
};