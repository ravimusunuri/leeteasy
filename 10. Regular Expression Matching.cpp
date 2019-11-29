class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        
        if (p_len == 0)
            return (s_len == 0);
        
        bool dp[s_len+1][p_len+1];
        memset(dp, 0, sizeof(dp));
        
        dp[0][0] = 1;
        for(int j=1; j<=p_len;j++) {
            if (p[j-1]=='*')
                dp[0][j] = dp[0][j-2];
        }
           
        for (int i=1; i<=s_len;i++) {
            for (int j=1; j<=p_len; j++) {
                if ((s[i-1] == p[j-1]) || (p[j-1] =='.')) {
                    dp[i][j] = dp[i-1][j-1];
                } else if ((p[j-1]=='*')) {
                    dp[i][j] = dp[i][j-2];
                    if ((p[j-2] == '.') || (p[j-2] == s[i-1])) {
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                } else {
                    dp[i][j] = false;
                }
                
            }
        }
        
        return dp[s_len][p_len];
        
    }
};
