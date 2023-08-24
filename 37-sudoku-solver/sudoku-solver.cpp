class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>> &board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){
                    for(char k='1'; k<='9'; k++){
                        if(isValid(board, k, i, j)){
                            board[i][j]=k;
                            if(solve(board)) return true;;
                            board[i][j]='.';
                        }
                    }
                    return false;   
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>> &board, char k, int row, int col){
        for(int i=0; i<9; i++){
            if(board[row][i]==k || board[i][col]==k) return false;
        }

        int blockRow = row/3 * 3;
        int blockCol = col/3 * 3;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[blockRow+i][blockCol+j]==k) return false;
            }
        }
        return true;
    }
};