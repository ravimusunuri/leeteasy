class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty())
            return res;
        int m=matrix.size(),n=matrix[0].size();
        int sr=0,sc=0,er=m-1,ec=n-1;
        while(sr<=er&&sc<=ec){
            for(int i=sc;i<=ec;++i)
                res.push_back(matrix[sr][i]);
            for(int i=sr+1;i<=er;++i)
                res.push_back(matrix[i][ec]);
            for(int i=ec-1;sr!=er&&i>=sc;--i)
                res.push_back(matrix[er][i]);
            for(int i=er-1;sc!=ec&&i>sr;--i)
                res.push_back(matrix[i][sc]);
            sr++,sc++;
            er--,ec--;
        }
        return res;
    }
};
