class NumArray {
public:
    vector<int>pref_nums;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        this->pref_nums=vector<int>(n+1);

        this->pref_nums[0]=0;

        for(int i=1; i<=n; i++){
            this->pref_nums[i]=this->pref_nums[i-1]+nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return this->pref_nums[right+1]-this->pref_nums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */