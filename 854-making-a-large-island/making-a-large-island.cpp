class DisJointSet {
public:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
     
    DisJointSet(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        int i;
        for(i=0; i<=n; i++) parent[i]=i;
    }

    int findupar(int node) {
        if(node==parent[node]) return node;
        return parent[node] = findupar(parent[node]);
    }

    void unionByRank(int u,int v) {
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

    void unionBySize(int u, int v) {
        int ulp_u = findupar(u);
        int ulp_v = findupar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisJointSet ds(n*n);
        // step 1
        for(int row=0; row<n; row++) {
            for(int col=0; col<n; col++) {
                if(grid[row][col]==0) continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for(int ind=0; ind<4; ind++) {
                    int newR = dr[ind] + row;
                    int newC = dc[ind] + col;
                    if(newR>=0 && newR<n && newC>=0 && newC<n && grid[newR][newC]==1) {
                        int nodeNo = row*n + col;
                        int adjNodeNo = newR*n + newC;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        // step 2
        int mx = 0;
        for(int row=0; row<n; row++) {
            for(int col=0; col<n; col++) {
                if(grid[row][col]==1) continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int> components;
                for(int ind=0; ind<4; ind++) {
                    int newR = dr[ind] + row;
                    int newC = dc[ind] + col;
                    if(newR>=0 && newR<n && newC>=0 && newC<n && grid[newR][newC]==1) {
                        components.insert(ds.findupar(newR*n + newC));
                    }
                }

                int totalSize = 0;
                for(auto it: components) {
                    totalSize+= ds.size[it];
                }
                mx = max(mx, totalSize+1);
            }
        }

        for(int cellNo=0; cellNo<n*n; cellNo++) {
            mx = max(mx, ds.size[ds.findupar(cellNo)]);
        }

        return mx;
    }
};