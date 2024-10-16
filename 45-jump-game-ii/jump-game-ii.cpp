class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, n = nums.size();
        int l = 0, r = 0, farthest = 0;
        if(n==1) return 0;
        while(r <= n-1){
            for(int ind = l; ind <= r; ind++){
                farthest=max(farthest, ind + nums[ind]);
                if(farthest>=n-1) return jumps+1;
            }
            l = r + 1;
            jumps=jumps+1;
            r = farthest;
        }
        return jumps;
    }
};