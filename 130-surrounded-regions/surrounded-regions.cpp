class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // Method 1 [DFS] O(2(n+m) + n*m*4), O(n*m)
        // int n = board.size(), m = board[0].size();
        // vector<vector<int>> vis(n, vector<int>(m, 0));
        // int delRow[] = {-1, 0, 1, 0};
        // int delCol[] = {0, 1, 0, -1};

        // for(int i=0; i<m; i++) {
        //     if(board[0][i] == 'O' && !vis[0][i]) dfs(0, i, vis, board, delRow, delCol); // first row
        //     if(board[n-1][i] == 'O' && !vis[n-1][i]) dfs(n-1, i, vis, board, delRow, delCol); // last row
        // }

        // for(int i=0; i<n; i++) {
        //     if(board[i][0] == 'O' && !vis[i][0]) dfs(i, 0, vis, board, delRow, delCol); // first col
        //     if(board[i][m-1] == 'O' && !vis[i][m-1]) dfs(i, m-1, vis, board, delRow, delCol); // last col
        // }

        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<m; j++) {
        //         if(!vis[i][j] && board[i][j]=='O') board[i][j] = 'X';
        //     }
        // }
        // return;

        // Method 2 [BFS]
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for(int i=0; i<m; i++) {
            if(board[0][i] == 'O' && !vis[0][i]) bfs(0, i, vis, board, delRow, delCol); // first row
            if(board[n-1][i] == 'O' && !vis[n-1][i]) bfs(n-1, i, vis, board, delRow, delCol); // last row
        }

        for(int i=0; i<n; i++) {
            if(board[i][0] == 'O' && !vis[i][0]) bfs(i, 0, vis, board, delRow, delCol); // first col
            if(board[i][m-1] == 'O' && !vis[i][m-1]) bfs(i, m-1, vis, board, delRow, delCol); // last col
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && board[i][j]=='O') board[i][j] = 'X';
            }
        }
        return;
    }

private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& board, int delRow[], int delCol[]) {
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && board[nRow][nCol]=='O') {
                dfs(nRow, nCol, vis, board, delRow, delCol);
            }
        }
    }

    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& board, int delRow[], int delCol[]) {
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            for(int i=0; i<4; i++) {
                int nRow = node.first + delRow[i];
                int nCol = node.second + delCol[i];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && board[nRow][nCol]=='O') {
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }
};