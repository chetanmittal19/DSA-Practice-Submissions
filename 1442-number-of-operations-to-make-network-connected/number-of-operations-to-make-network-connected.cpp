class DisJointSet
{
    public :
    vector<int> rank;
    vector<int> parent;
     
    DisJointSet(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1);
        int i;
        for(i=0; i<=n; i++) parent[i]=i;
    }

    int findupar(int node) {
        if(node==parent[node]) return node;
        return parent[node] = findupar(parent[node]);
    }

    void unionbyrank(int u,int v) {
        int pu=findupar(u);
        int pv=findupar(v);
        if(pu==pv) return;

        if(rank[pu]<rank[pv]) parent[pu]=pv;
        else if(rank[pv]<rank[pu]) parent[pv]=pu;
        else {
            parent[pu]=pv;
            rank[pv]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& arr) {
        // Method 1 [DisJoint DS]
        DisJointSet ds(n);
        int cnt=0;
        for(auto it : arr) {
            int u=it[0];
            int v=it[1];
            if(ds.findupar(u)!=ds.findupar(v)) ds.unionbyrank(u,v);
            else cnt++;
        }

        int nc=0;
        int i;
        for(i=0; i<n; i++) {
            if(ds.parent[i]==i) nc++;
        }
        if(cnt<nc-1) return -1;
        return nc-1;

        // Method 2 [DFS]
        // int len = arr.size();
        // if(len<n-1) return -1;
        // vector<int> adj[n];
        // for(auto v : arr) {
        //     adj[v[0]].push_back(v[1]);
        //     adj[v[1]].push_back(v[0]);
        // }

        // vector<bool> visited(n, false);
        // int ans = 0;
        // for(int i=0; i<n; i++)
        // if(!visited[i]) {
        //     dfs(adj, visited, i);
        //     ans++;
        // }
        // return ans - 1;
    }

    void dfs(vector<int> adj[], vector<bool> &visited, int src) {
        visited[src] = true;
        for(int i : adj[src]) {
            if(!visited[i]) dfs(adj, visited, i);
        }
    }
};