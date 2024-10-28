class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int>st(begin(nums),end(nums));
        int streak=0;

        for(int &num: nums){
            int s=0;
            long long curr=num;
            while(st.find(curr)!=st.end()){
                s++;
                if(curr*curr>1e5) break;
                curr=curr*curr;
            }
            streak=max(streak,s);
        }

        if(streak<2) return -1;
        return streak;
    }
};