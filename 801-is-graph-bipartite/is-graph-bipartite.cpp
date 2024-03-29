class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // Method 1 [DFS] O(v + 2E), O(v)
        // can also be done with BFS, i think
        // int v = graph.size();
        // int color[v];
        // for(int i=0; i<v; i++) color[i] = -1;
        // for(int i=0; i<v; i++) {
        //     if(color[i]==-1) {
        //         if(dfs(i, 0, color, graph)==false) return false;
        //     }
        // }
        // return true;

        // Method 2 [BFS] 
        int v = graph.size();
        int color[v];
        for(int i=0; i<v; i++) color[i] = -1;
        for(int i=0; i<v; i++) {
            if(color[i]==-1) {
                if(bfs(i, 0, color, graph)==false) return false;
            }
        }
        return true;
    }

private:
    bool dfs(int node, int col, int color[], vector<vector<int>>& graph) {
        color[node] = col;
        for(auto it: graph[node]) {
            if(color[it]==-1) {
                if(dfs(it, !col, color, graph)==false) return false;
            } else if(color[it]==col) return false;
        }
        return true;
    }

    bool bfs(int node, int col, int color[], vector<vector<int>>& graph) {
        color[node] = col;
        queue<int> q;
        q.push(node);
        while(!q.empty()) {
            int n= q.front();
            int clr = color[n];
            q.pop();
            for(auto it: graph[n]) {
                if(color[it]==-1) {
                    color[it] = !clr;
                    q.push(it);
                } else if(color[it]==clr) return false;
            }
        }
        return true;
    }
};