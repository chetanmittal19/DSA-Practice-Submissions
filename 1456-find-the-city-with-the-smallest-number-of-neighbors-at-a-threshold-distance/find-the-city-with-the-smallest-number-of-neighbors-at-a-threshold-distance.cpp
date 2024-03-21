class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Method 1 [Floyd Algo] O(V^3), O(V)
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
		for (auto it : edges) {
			dist[it[0]][it[1]] = it[2];
			dist[it[1]][it[0]] = it[2];
		}
		for (int i = 0; i < n; i++) dist[i][i] = 0;
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
						continue;
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		int cntCity = n;
		int cityNo = -1;
		for (int city = 0; city < n; city++) {
			int cnt = 0;
			for (int adjCity = 0; adjCity < n; adjCity++) {
				if (dist[city][adjCity] <= distanceThreshold)
					cnt++;
			}

			if (cnt <= cntCity) {
				cntCity = cnt;
				cityNo = city;
			}
		}
		return cityNo;

        // Method 2 [DijKstra] O(V*ElogV), O(V+E)
        // vector<pair<int,int>> adj[n];
        // for(auto it:edges) {
        //     adj[it[0]].push_back({it[1],it[2]});
        //     adj[it[1]].push_back({it[0],it[2]});
        // }
        
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // int cityno, mincitycount = 1e9;
        // for(int i=0;i<n;i++) {
        //     vector<int> dist(n,1e9);
        //     pq.push({0,i});
        //     dist[i]=0;

        //     while(!pq.empty()) {
        //         int distance=pq.top().first;
        //         int node=pq.top().second;
        //         pq.pop();
        //         for(auto it:adj[node]) {
        //             int adjNode=it.first;
        //             int adjWeight=it.second;
        //             if(distance + adjWeight < dist[adjNode]) {
        //                 dist[adjNode] = distance + adjWeight;
        //                 pq.push({dist[adjNode],adjNode});
        //             }
        //         }
        //     }

        //     int count=0;
        //     for(int j=0;j<n;j++) {
        //         if(dist[j]<=distanceThreshold) count++;
        //     }
        //     if(count<=mincitycount) {
        //         mincitycount=count;
        //         cityno = i;
        //     }
        // }
        // return cityno;
    }
};