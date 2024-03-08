class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int iniColor = image[sr][sc];
        int[][] ans = image;
        int[] delRow = {-1, 0, 1, 0};
        int[] delCol = {0, 1, 0, -1};
        dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor);
        return ans;
    }

    private void dfs(int sr, int sc, int[][] ans, int[][] image, int newColor, int[] delRow, int[] delCol, int iniColor) {
        ans[sr][sc] = newColor;
        int n = image.length;
        int m = image[0].length;
        for(int i=0; i<4; i++) {
            int nRow = sr + delRow[i];
            int nCol = sc + delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && image[nRow][nCol]==iniColor && ans[nRow][nCol]!=newColor) {
                dfs(nRow, nCol, ans, image, newColor, delRow, delCol, iniColor);
            }
        }
    }
}