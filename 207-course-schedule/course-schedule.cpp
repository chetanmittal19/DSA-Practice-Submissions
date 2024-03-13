class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites ) {
        // Method 1 [BFS]
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++) indegree[i] = 0;
        for (auto it : prerequisites ) {
			adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
		}

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        if(cnt==V) return true;
        return false;
    }
};