class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        // Method 1 [DFS] O(2(n+m) + n*m*4 + n*m), O(n*m)
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for(int i=0; i<m; i++) {
            if(grid[0][i] == 1 && !vis[0][i]) dfs(0, i, vis, grid, delRow, delCol); // first row
            if(grid[n-1][i] == 1 && !vis[n-1][i]) dfs(n-1, i, vis, grid, delRow, delCol); // last row
        }

        for(int i=0; i<n; i++) {
            if(grid[i][0] == 1 && !vis[i][0]) dfs(i, 0, vis, grid, delRow, delCol); // first col
            if(grid[i][m-1] == 1 && !vis[i][m-1]) dfs(i, m-1, vis, grid, delRow, delCol); // last col
        }

        int res = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]==1) res++;
            }
        }
        return res;

        // Method 2 [BFS] O(2(n+m) + n*m*4 + n*m), O(n*m)
        // int n = grid.size(), m = grid[0].size();
        // vector<vector<int>> vis(n, vector<int>(m, 0));
        // int delRow[] = {-1, 0, 1, 0};
        // int delCol[] = {0, 1, 0, -1};

        // for(int i=0; i<m; i++) {
        //     if(grid[0][i] == 1 && !vis[0][i]) bfs(0, i, vis, grid, delRow, delCol); // first row
        //     if(grid[n-1][i] == 1 && !vis[n-1][i]) bfs(n-1, i, vis, grid, delRow, delCol); // last row
        // }

        // for(int i=0; i<n; i++) {
        //     if(grid[i][0] == 1 && !vis[i][0]) bfs(i, 0, vis, grid, delRow, delCol); // first col
        //     if(grid[i][m-1] == 1 && !vis[i][m-1]) bfs(i, m-1, vis, grid, delRow, delCol); // last col
        // }

        // int res = 0;
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<m; j++) {
        //         if(!vis[i][j] && grid[i][j]==1) res++;
        //     }
        // }
        // return res;
    }

private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, int delRow[], int delCol[]) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && grid[nRow][nCol]==1) {
                dfs(nRow, nCol, vis, grid, delRow, delCol);
            }
        }
    }

    // void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, int delRow[], int delCol[]) {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     vis[row][col] = 1;
    //     queue<pair<int, int>> q;
    //     q.push({row, col});

    //     while(!q.empty()) {
    //         auto node = q.front();
    //         q.pop();
    //         for(int i=0; i<4; i++) {
    //             int nRow = node.first + delRow[i];
    //             int nCol = node.second + delCol[i];
    //             if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && grid[nRow][nCol]==1) {
    //                 vis[nRow][nCol] = 1;
    //                 q.push({nRow, nCol});
    //             }
    //         }
    //     }
    // }
};