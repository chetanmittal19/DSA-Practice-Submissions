class Solution {
    class Pair {
        int sr;
        int sc;
        Pair(int sr, int sc) {
            this.sr = sr;
            this.sc = sc;
        }
    }

    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        // Create a copy array in both method if orignal array modification is not allowed
        // Method 1 [DFS] O(n*m*4), O(n*m)->recursion
        // int iniColor = image[sr][sc];
        // int[][] ans = image;
        // int[] delRow = {-1, 0, 1, 0};
        // int[] delCol = {0, 1, 0, -1};
        // dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor);
        // return ans;

        // Method 2 [BFS] O(n*m*4), O(n*m)
        int iniColor = image[sr][sc];
        int n = image.length;
        int m = image[0].length;
        boolean[][] vis = new boolean[n][m];
        int[][] ans = image;

        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(sr, sc));
        vis[sr][sc] = true;
        int[] delRow = {-1, 0, 1, 0};
        int[] delCol = {0, 1, 0, -1};

        while(!q.isEmpty()) {
            Pair p = q.poll();
            ans[p.sr][p.sc] = newColor;
            for(int i=0; i<4; i++) {
                int nRow = p.sr + delRow[i];
                int nCol = p.sc + delCol[i];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && image[nRow][nCol]==iniColor) {
                    q.add(new Pair(nRow, nCol));
                    vis[nRow][nCol] = true;
                }
            }
        }
        return ans;
    }

    private void dfs(int sr, int sc, int[][] ans, int[][] image, int newColor, int[] delRow, int[] delCol, int iniColor) {
        ans[sr][sc] = newColor;
        int n = image.length;
        int m = image[0].length;
        for(int i=0; i<4; i++) {
            int nRow = sr + delRow[i];
            int nCol = sc + delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && image[nRow][nCol]==iniColor) {
                dfs(nRow, nCol, ans, image, newColor, delRow, delCol, iniColor);
            }
        }
    }
}