class DisJointSet {
public:
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
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        for(auto it: stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisJointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;
        for(auto it: stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionByRank(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;
        for(auto it: stoneNodes) {
            if(ds.findupar(it.first) == it.first) cnt++;
        }
        return stones.size() - cnt;
    }
};