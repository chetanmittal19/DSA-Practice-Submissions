class Solution {
    public void setZeroes(int[][] matrix) {
        // Method 1 [Brute Force] O(N^3) + O(N^2) = O(N^3), O(1);
        // If the array contains only positive elements, then we can iterate over whole array and as soon as we find a 0 we mark that entire row and column with -1 using 3rd nested loop O(N^3)
        // After iterating all the 0 and corresponding marking -1, reiterate the array and replace -1 to 0

        // Method 2 [Naive] O(N^2) + O(N^2) = O(N^2), O(N^2)
        // If the values contains negative values also, then create new array and make changes in that new array and return that array.

        //Method 3 [Better] O(N^2) + O(N^2) = O(N^2), O(N) + O(M) = O(n)
        // int row = matrix.length;
        // int col = matrix[0].length;

        // int[] rowMat = new int[row];
        // int[] colMat = new int[col];

        // for(int i=0; i<row; i++){
        //     for(int j=0; j<col; j++){
        //         if(matrix[i][j]==0){
        //             rowMat[i]=1;
        //             colMat[j]=1;
        //         }
        //     }
        // }

        // for(int i=0; i<row; i++){
        //     for(int j=0; j<col; j++){
        //         if(rowMat[i]==1 || colMat[j]==1) matrix[i][j]=0;
        //     }
        // }

        // Method 4 [Optimal] O(N^2) + O(N^2) = O(N^2), O(1)
        int m = matrix.length;
        int n = matrix[0].length;
        int x=1, y=1;
        for(int i=0; i<n; i++) if(matrix[0][i]==0) x=0;
        for(int i=0; i<m; i++) if(matrix[i][0]==0) y=0;

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=1; i<n; i++){
            if(matrix[0][i]==0){
                for(int j=1; j<m; j++){
                    matrix[j][i] = 0;
                }
            }
        }

        for(int i=1; i<m; i++){
            if(matrix[i][0]==0){
                for(int j=1; j<n; j++){
                    matrix[i][j] = 0;
                }
            }
        }

        if(y==0) for(int i=0; i<m; i++) matrix[i][0] = 0;
        if(x==0) for(int i=0; i<n; i++) matrix[0][i] = 0;
    }
}