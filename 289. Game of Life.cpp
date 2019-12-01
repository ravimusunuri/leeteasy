class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int x[] = {-1,-1, -1, 0, 1, 1, 1, 0};
        int y[] = {-1, 0,  1, 1, 1, 0, -1, -1};
        for (int i=0; i<m;i++) {
            for (int j=0; j<n; j++) {
                int count = 0;
                for (int k=0; k<8; k++) {
                    int a = i + x[k];
                    int b = j + y[k]; 
                    if ((a >=0 && a<m) && ( b>=0 && b<n) && (board[a][b] & 0x1)) {
                        count++;   
                    }
                }
                
                if (board[i][j] & 0x1) {
                    if ((count == 2) || (count == 3))
                        board[i][j] = board[i][j] | 0x11;
                } else {
                    if (count ==3 )
                        board[i][j] = board[i][j] | 0x10;
                }
            }
        }
        
        for (int i=0; i<m;i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j]& 0x10) {
                    board[i][j] = 1;
                }  else {
                    board[i][j] = 0;
                }
            }
        }
        
    }
};
