class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        // Mij -> Mj(n-1-i) -> M(n-1-i)(n-1-j) -> M(n-1-j)i -> Mij
        // Mij in the top left part
        
        int n = matrix.size();
        
        for(int i=0; i < n/2; i++)
        {
            for(int j=0; j <= (n-1)/2; j++)
            {
                int tmp = matrix[i][j];
                
                std::swap(tmp, matrix[j][n-1-i]);
                std::swap(tmp, matrix[n-1-i][n-1-j]);
                std::swap(tmp, matrix[n-1-j][i]);
                std::swap(tmp, matrix[i][j]);
            }
        }
    }
};
