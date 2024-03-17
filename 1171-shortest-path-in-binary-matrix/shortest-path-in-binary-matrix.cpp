class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        if(n==1 && m==1 && grid[0][0]==0) return 1;
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = 1;
        q.push({1, {0, 0}}); // {dis, {row, col}}
        int dr[] = {0, 0, 1, -1, 1, -1, 1, -1};
        int dc[] = {1, -1, 0, 0, 1, -1, -1, 1};
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i=0; i<8; i++) {
                int newR = r + dr[i];
                int newC = c + dc[i];
                if(newR>=0 && newR<n && newC>=0 && newC<m && grid[newR][newC]==0 && dis+1<dist[newR][newC]) {
                    dist[newR][newC] = dis+1;
                    if(newR==n-1 && newC==m-1) return dis+1;
                    q.push({1+dis, {newR, newC}});
                }
            }
        }
        return -1;
    }
};