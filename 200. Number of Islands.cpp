class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visit, int i, int j) {
        int x[] = {-1, 1, 0, 0};
        int y[] = { 0, 0, -1, 1};
        
        for (int dir=0;dir <4; dir++) {
            int a = i + x[dir];
            int b = j + y[dir];
            
            if ((a < 0) || (a >= grid.size()) || (b<0) || (b>=grid[0].size()) || visit[a][b] || (grid[a][b] == '0')) {
                continue;
            }
            
    
            visit[a][b]=true;
            dfs(grid, visit, a, b);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m==0) return 0;
        int n = 4;
        vector<vector<bool>> visited;
        visited.resize(m);
        for (int j=0;j<grid.size();j++) {
            visited[j].resize(grid[0].size());
        }
        int count = 0;
        for (int i=0;i<grid.size();i++) {
            for (int j=0; j<grid[0].size();j++) {
                if (!visited[i][j] && (grid[i][j] == '1')) {
                    visited[i][j]=true;
                    dfs(grid, visited, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
