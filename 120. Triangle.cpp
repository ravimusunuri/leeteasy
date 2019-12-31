class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if(m == 1)
            return triangle[0][0];
        if(m == 2)
            return triangle[0][0] + min(triangle[1][0], triangle[1][1]);
        triangle[1][0] += triangle[0][0];
        triangle[1][1] += triangle[0][0];
        for(int i = 2; i < m; i++) {
            for(int j = 0; j < triangle[i].size(); j++) {
                if(j == 0)
                    triangle[i][j] += triangle[i-1][0];
                else if(j == triangle[i].size()-1)
                    triangle[i][j] += triangle[i-1][j-1];
                else 
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
        return *min_element(triangle[m-1].begin(), triangle[m-1].end());
    }
};
