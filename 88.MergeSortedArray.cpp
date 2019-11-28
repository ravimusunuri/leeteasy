class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> sorted;
        int i = 0;
        int j = 0;
        
        if (n == 0) {
            return;
        }
        
        if (m == 0) {
            for(int k=0;k<n;k++)
               nums1[k]=nums2[k];
        }
        
        while ((i < m) || (j < n)) {
            
            if ((((i<m) && (j<n)) && (nums1[i] < nums2[j])) ||
                (j == n)) {
                sorted.push_back(nums1[i]);
                i++;
            } else {
                sorted.push_back(nums2[j]);
                j++;
            }
        }
        
        for(int k=0;k<(m+n);k++)
            nums1[k]=sorted[k];
        
        return;
    }
};
