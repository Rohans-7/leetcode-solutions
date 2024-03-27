class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int currMisPos=1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                currMisPos=1;
            }
            else if(nums[i]!=currMisPos && nums[i]>0){
                continue;
            }
            else if(nums[i]<0){
                continue;
            }
            else{
                currMisPos++;
            }
        }
        return currMisPos;
    }
};