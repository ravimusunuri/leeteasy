class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int low = 0;
        int hi = nums.size()-1;
        
        vector<int> res;
        int start_idx = -1;
        int end_idx = -1;
        while (low <= hi) {
            int mid = (low+hi)/2;
            
            if (nums[mid] == target) {
                start_idx = mid;
                while ((start_idx > 0) && (nums[start_idx] == nums[start_idx-1])) {
                    start_idx--;
                }
                end_idx = mid;
                while ((end_idx < nums.size()-1) && (nums[end_idx] == nums[end_idx+1])) {
                    end_idx++;
                }
                break;
            } else if (target < nums[mid]) {
                hi = mid-1;
            } else {
                low = mid+1;
            }
        }
        
        res.push_back(start_idx);
        res.push_back(end_idx);
        return res;
    }
};
