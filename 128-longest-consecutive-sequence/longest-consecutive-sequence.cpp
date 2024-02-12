class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        set<int>s;

        vector<int>arr;

        for(auto &a: nums){
            s.insert(a);
        }

        for(auto e:s){
            arr.push_back(e);
        }

        int mx=1;

        int currCnt=1;

        for(int i=1; i<arr.size(); i++){
            if(arr[i-1]==arr[i]-1){
                currCnt++;
                mx=max(mx,currCnt);
            }
            else{
                currCnt=1;
            }
        }

        return mx;
    }
};