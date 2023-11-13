class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // 2 pointers:
                int m = j + 1;
                int l = n - 1;
                while (m < l) {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[m];
                    sum += nums[l];
                    if (sum == k) {
                        vector<int> temp = {nums[i], nums[j], nums[m], nums[l]};
                        ans.push_back(temp);
                        m++; l--;

                        //skip the duplicates:
                        while (m < l && nums[m] == nums[m - 1]) m++;
                        while (k < l && nums[l] == nums[l + 1]) l--;
                    }
                    else if (sum < k) m++;
                    else l--;
                }
            }
        }

        return ans;
    }
};