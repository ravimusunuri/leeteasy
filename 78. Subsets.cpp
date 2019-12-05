class Solution {
public:
    void
    generateSubsets(int idx, vector<int>& nums, vector<int> cur, vector<vector<int>>& res) {
        if (idx == nums.size()) {
                res.push_back(cur);
                return;
        }

        generateSubsets(idx+1, nums, cur, res);
        cur.push_back(nums[idx]);
        generateSubsets(idx+1, nums, cur, res);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        generateSubsets(0, nums, cur, res);
        return res;
    }
};
