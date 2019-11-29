class Solution {
public:
    int countPrimes(int n) {
        
        if (n <2)
            return 0;
        
        bool dp[n]; 
        memset(dp, true, sizeof(dp)); 
  
        
        for(int i=2; i*i<n; i++) {
            if (dp[i] == true) {
                for (int j=i*i; j<n;j+=i) {
                    dp[j]=false;
                }
            }
        }
        int count = 0;
        for (int i=2; i<n; i++) {
            if (dp[i] == true) {
                count++;
            }
        }
        return count;        
    }
};
