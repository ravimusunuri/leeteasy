class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr_max = 1, curr_min = 1, overall_max = INT_MIN;
			for (int i = 0; i < nums.size(); i++) {
				int potential_max = nums[i] * curr_max;
				int potential_min = nums[i] * curr_min;
				curr_max = max(nums[i], max(potential_max, potential_min));
				curr_min = min(nums[i], min(potential_max, potential_min));
				overall_max = max(curr_max, overall_max);
			}
		return overall_max;
    }
};
