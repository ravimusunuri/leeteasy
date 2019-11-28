class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myset;
        vector<int> res;
        
        for (int i=0; i<nums.size();i++) {
            int tmp = target - nums[i];
            auto it = myset.find(tmp);
            if (it != myset.end()) {
                res.push_back(it->second);
                res.push_back(i);
                return res;
            } else {
                myset.insert({nums[i],i});
            }
        }
        return res;
    }
};
