class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // Method 1 [DFS] O(n*m*4), O(n*m)
        // int n = grid.size();
        // int m = grid[0].size();
        // vector<vector<int>> vis(n, vector<int>(m, 0));
        // int cnt = 0;
        // for(int row=0; row<n; row++) {
        //     for(int col=0; col<m; col++) {
        //         if(!vis[row][col] && grid[row][col]=='1') {
        //             cnt++;
        //             dfs(row, col, vis, grid);
        //         }
        //     }
        // }
        // return cnt;

        // Method 2 [BFS]
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for(int row=0; row<n; row++) {
            for(int col=0; col<m; col++) {
                if(!vis[row][col] && grid[row][col]=='1') {
                    cnt++;
                    dfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }

private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        for(int i=0; i<4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && grid[nRow][nCol]=='1') {
                dfs(nRow, nCol, vis, grid);
            }
        }
    }

    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            for(int i=0; i<4; i++) {
                int nRow = node.first + delRow[i];
                int nCol = node.second + delCol[i];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && grid[nRow][nCol]=='1') {
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }
};