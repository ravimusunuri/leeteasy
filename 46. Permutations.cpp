class Solution {
public:
    
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    void permute(vector<int>& nums, int start, vector<vector<int>>& res) {
        if (start == nums.size()) {
            res.push_back(nums);
        }
        
        for(int i=start; i<nums.size(); i++) {
            swap(nums, start, i);
            permute(nums, start+1, res);
            swap(nums, i, start);
        }
    }
        
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size()) {
            permute(nums, 0, res);
        }
        return res;
    }
};
