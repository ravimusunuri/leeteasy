class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool rows[matrix.size()];
        memset(rows, 1, sizeof(rows));
        bool cols[matrix[0].size()];
        memset(cols, 1, sizeof(cols));
        
        for (int i=0; i< matrix.size();i++) {
            for (int j=0; j< matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }
        
         for (int i=0; i< matrix.size(); i++) {
            for (int j=0; j< matrix[0].size(); j++) {
                if ((rows[i] == 0) || (cols[j] == 0)) {
                   matrix[i][j]=0;
                }
            }
        }
    }
};
