class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;

        int n = nums.size();
        int i=0; 
        int j;
        while (i<n) {
            j = i;
            
            while ( j+1 < n) {
                if ((nums[j] + 1) == nums[j+1]) {
                    j++;
                } else {
                    break;
                }
            }
            
            if (i  == j) {
                res.push_back(to_string(nums[i]));
            } else {
                res.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            }
            i = j+1;
        }
        
        return res;
    }
};
