class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[366] = {0}; // day_cost[0] is sentry
        int tick_idx = 0;
        for (int day = 1; day <= 365 && tick_idx < days.size(); ++ day) {
            if (days[tick_idx] == day) {
                int cost1 = day >= 1 ? dp[day - 1] + costs[0] : costs[0];
                int cost7 = day >= 7 ? dp[day - 7] + costs[1] : costs[1];
                int cost30 = day >= 30 ? dp[day - 30] + costs[2] : costs[2];
                dp[day] = min(min(cost1, cost7), cost30);
                ++ tick_idx;
            } else {
                dp[day] = dp[day - 1];
            }
        }
        return dp[*days.rbegin()];
    }
};
