class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mySet;
        int max_len = 1;
        
        if (nums.size() < 2) {
            return nums.size();
        }
        
        for (int i=0; i< nums.size(); i++) {
                mySet.insert(nums[i]);
        }
        
        for (int i=0; i< nums.size(); i++) {
            if(mySet.find(nums[i]-1)==mySet.end()){
                int count = 1;
                while ((mySet.find(nums[i]+count)) != mySet.end()) {
                    count++;
                }
                
                if (count > max_len) {
                    max_len = count;
                }
            }
        }
        
        return max_len;
    }
};
