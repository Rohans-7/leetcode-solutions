class Solution {
public:
    bool static comp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);

        int ans=0;
        int start=intervals[0][0],end=intervals[0][1];
        for(int i=1; i<intervals.size(); ++i){
            if(intervals[i][0]<end){
                ans++;
            }
            else{
                end=intervals[i][1];
            }
        }

        return ans;
    }
};