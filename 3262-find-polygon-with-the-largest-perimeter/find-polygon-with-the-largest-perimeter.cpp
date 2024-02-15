class Solution {
public:
    long long sumNums(vector<int>nums){
        long long sum=0;
        for(auto &i: nums){
            sum+=i;
        }
        return sum;
    }
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();

        long long sum=sumNums(nums);
        sort(nums.begin(),nums.end());

        for(int i=n-1; i>=2; --i){
            if(sum-nums[i]>nums[i]){
                return sum;
            }

            sum-=nums[i];
        }

        return -1;
    }
};