class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {

        int sum = std::accumulate(stones.begin(), stones.end(), 0);

        int target = sum/2;

        vector<int> dp(target+1, 0);
        
       for(auto stone :  stones)
        {
            for(int w = target; w >= 0; --w )
            {
                if (w - stone >= 0)
                    dp[w] = max(stone + dp[w-stone], dp[w]);
            }
        }
        return sum - 2*dp[target];
    }
};
