class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(i!=j && isConnected[i][j]!=0){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);
        queue<int> q;
        int res = 0;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                res++;
                q.push(i);
                vis[i] = 1;
                traverseComponent(adj, q, vis);
            }
        }
        return res;
    }

private:
    void traverseComponent(vector<int> adj[], queue<int> &q, vector<int>& vis) {
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it: adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
};