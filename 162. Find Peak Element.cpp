class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int low = 0;
        int hi = nums.size() -1;
        int mid = 0;
        while (low <= hi) {
            mid = (low+hi)/2;
            
            if (((mid == 0) || (nums[mid] > nums[mid-1])) && 
                ((mid == nums.size()-1) || (nums[mid]> nums[mid+1]))) {
                return mid;
            } else if ((mid > 0) && (nums[mid-1] > nums[mid])) {
                hi = mid-1;
            } else {
                low = mid+1;
            }
        }
        
        return -1;
    }
};
