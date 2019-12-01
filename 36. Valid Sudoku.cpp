class Solution {
public:
    bool isValidBox(vector<vector<char>>& board, int s_row, int s_col) {
        unordered_set<char> mySet;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                int x = s_row + i;
                int y = s_col + j;

                if(board[x][y] != '.')  {
                    if (mySet.find(board[x][y]) == mySet.end()) {
                        mySet.insert(board[x][y]);
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    bool isRowValid(vector<vector<char>>& board, int row) {
        unordered_set<char> mySet;
        for (int j=0; j< 9; j++) {
            if(board[row][j] != '.')  {
                if (mySet.find(board[row][j]) == mySet.end()) {
                    mySet.insert(board[row][j]);
                } else {
                        return false;
                } 
            }
        }
        return true;
    }
    
    bool isColValid(vector<vector<char>>& board, int col) {
        unordered_set<char> mySet;
        for (int i=0; i< 9; i++) {
            if(board[i][col] != '.')  {
                if (mySet.find(board[i][col]) == mySet.end()) {
                    mySet.insert(board[i][col]);
                } else {
                        return false;
                } 
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (int i=0; i<9;i++) {
            if (isRowValid(board,i) == false) {
                return false;
            }
            if (isColValid(board,i) == false) {
                return false;
            }
        }
        
        for (int i=0; i<9; i+=3) {
            for (int j=0; j<9; j+=3 ) {
                if ((isValidBox(board,i,j)) == false) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
