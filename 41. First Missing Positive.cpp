class Solution {
public:
    int removeNegative(vector<int>& nums) {
        int j = 0;
        for (int i= 0; i< nums.size(); i++) {
            if (nums[i] > 0) {
                int tmp = nums[j];
                nums[j] =nums[i];
                nums[i] = tmp;
                j++;
            }
        }
        return j;
    }
    
    int findMissing (vector<int>& nums, int sz) {
        for (int i=0;i<sz;i++) {
            int idx = abs(nums[i])-1;
            if ((idx < sz) && (nums[idx] > 0)) {
                nums[idx] = -nums[idx];
            }
        }
        for (int i=0;i<sz;i++)
            if (nums[i] > 0)
                return i+1;
        return sz+1;
    }
    
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 1;
        }
        int sz = removeNegative(nums);
        return(findMissing(nums, sz));
    }
        
};
