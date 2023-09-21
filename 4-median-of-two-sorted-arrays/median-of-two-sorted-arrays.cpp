class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int n1=n+m;
        vector<int>ans(n1);
        int i=0;
        int j=0;
        int k=0;
        while(i<n && j<m)
        {
            if(nums1[i]<nums2[j])
            {
                ans[k++]=nums1[i++];
            }
            else
            {
                ans[k++]=nums2[j++];
            }
        }
        while(i<n)
        {
            ans[k++]=nums1[i++];
        }
        while(j<m)
        {
            ans[k++]=nums2[j++];
        }
        int mid=(n1)/2;
        if(n1&1)
        {
            return ans[mid];
        }
        double median=(ans[mid]+ans[mid-1])/2.0;
        return median;
    }
};