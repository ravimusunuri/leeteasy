class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dp[nums.size()];
        memset(dp, false, sizeof(dp));
        
        dp[0] = true;
        
        for (int i=1; i<nums.size(); i++) {
            for (int j=0; j<i; j++) {
                if (nums[j] >= (i-j) && (dp[j] == true)) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[nums.size()-1];
    }
};
