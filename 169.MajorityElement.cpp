class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_idx = 0;
        int count = 1;
        
        for (int i=1; i<nums.size();i++) {
            if (nums[i] == nums[maj_idx]) {
                count++;
            } else {
                count --;
            }
            
            if (count == 0) {
                maj_idx = i;
                count = 1;
            }
        }
        return nums[maj_idx];
    }
};
