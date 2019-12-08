class Solution {
public:
    
    bool isSafe(vector<vector<char>>& board, int i, int j) {
        if ((i<0) || (i>=board.size()) || (j<0) || (j>=board[0].size())) {
            return false;
        }    
        return true;
    }
    
    bool search(vector<vector<char>>& board, vector<vector<bool>>& visit, string word, int i, int j, int idx) {
        int x[] = {0, 0, -1, 1};
        int y[] = {1, -1, 0, 0};

        if (idx >= word.length())
            return false;
        
        for (int dir=0;dir<4; dir++) {
            int a = i + x[dir];
            int b = j + y[dir];
            
            if (isSafe(board, a, b) && (visit[a][b] == false)) {
                if (word[idx] == board[a][b]) {
                    if (idx == (word.length()-1)) {
                        return true;
                    } else {
                        visit[a][b] = true;
                        if (search(board, visit, word, a, b, idx+1)) {
                            return true;
                        };
                        visit[a][b] = false;
                    }
                }
            }  
        }
        return false;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        if (word.length() == 0)
            return (board.size() == 0);
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
        for(int i=0; i< board.size(); i++) {
            for (int j=0; j< board[0].size();j++){
                
                if (word[0] == board[i][j]) {
                    if (word.length()  > 1) {
                        visit[i][j] = true;
                        if (search(board, visit, word, i, j, 1)) {
                            return true;
                        }
                        visit[i][j] = false;
                    } else {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
