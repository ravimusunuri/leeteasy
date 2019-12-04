class Solution {
public:
    int n, m, ans;
   
    int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, 1, 0, -1};
    bool safe(int x, int y){
      if(x >= 0 && x < n && y >= 0 && y<m)
        return true;
      return false;
    }
    vector<vector<int>> dp;
    
    void dfs(int p, int q, int len, vector<vector<int>>& mat){
      int i, j, k;
      
      if(dp[p][q] >= len) 
          return;
      
      dp[p][q] = len;
    
      for(k=0; k<4; k++){
        int x1 = p + x[k];
        int y1 = q + y[k];
        
        if(safe(x1, y1)){
          if(mat[x1][y1] > mat[p][q]){
            dfs(x1, y1, dp[p][q] + 1, mat);
          }
        }
      }
    }
    
    int longestIncreasingPath(vector<vector<int>>& mat) {
      int i, j, f;
      ans = 0;
      n = mat.size(); 
      if(n == 0) return 0;
      
      m = mat[0].size();
      dp.resize(n, vector<int>(m, INT_MIN));
      
      if(n == 1 && m == 1) 
          return 1;

      for(i=0; i< n; i++){
        for(j=0; j<m; j++){
         dfs(i, j, 1, mat);
        }
      }
    
      ans = 0;
      for(i=0; i<n; i++){
        for(j=0; j< m; j++){
          if(ans < dp[i][j]) 
              ans = dp[i][j];
        }
      }
      return ans;
    }
};
