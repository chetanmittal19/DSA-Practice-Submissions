class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;
        int leastTime = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!pq.empty()) {
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            leastTime = max(leastTime, time);
            if(row == n-1 && col == n-1) break;
            for(int i=0; i<4; i++) {
                int newR = dr[i] + row;
                int newC = dc[i] + col;
                if(newR>=0 && newR<n && newC>=0 && newC<n && !vis[newR][newC]) {
                    vis[newR][newC] = 1;
                    pq.push({grid[newR][newC], {newR, newC}});
                }
            }
        }
        return leastTime;
    }
};