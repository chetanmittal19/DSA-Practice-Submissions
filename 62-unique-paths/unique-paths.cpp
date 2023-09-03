class Solution {
public:
    int uniquePaths(int m, int n) {
        // Method 1 [Recursion & Backtracking]
        // return paths(m, n, 0, 0);

        //Method 2 [DP] O(N^2), O(N^2)
        vector<vector<int>> d(m, vector(n, 1));
        for(int col = 1; col < m; ++col) {
            for(int row = 1; row < n; ++row) {
                d[col][row] = d[col - 1][row] + d[col][row - 1];
            }
        }
        return d[m - 1][n - 1];
    }

    // int paths(int m, int n, int i, int j){
    //     if(i>=m || j>=n) return 0;
    //     if(i==m-1 && j==n-1) return 1;
        
    //     return paths(m, n, i+1, j) + paths(m, n, i, j+1);
    // }
};