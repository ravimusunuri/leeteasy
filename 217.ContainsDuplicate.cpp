class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> myset;
        
        for (int i=0;i<nums.size();i++){
            if (myset.find(nums[i]) == myset.end()){
                myset.insert(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};
