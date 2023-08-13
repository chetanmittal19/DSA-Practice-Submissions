class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        //Method 1 (Brute Force) O(row*col), O(1)

        //Method 2 [Binary Search] o(row * log(col)) = O(nlogm), O(1)
        //since each row is sorted, so we can apply binary search in each row to find out the element

        //Method 3 [Optimisation of Method 2] O(row) + O(log(col)), O(1)
        //instead of applying binary search in each row, we check if the element is in between the 
        //first and last element of that row or not. If not, then we move to next row else if the element is 
        //in between that row, than we apply binary search on that row and return the result of that.

        //Method 4 (ladder technique) O(row+col), O(1)
        // int i =0, j = matrix[0].length-1;
        // while(j>=0 && i<matrix.length){
        //     if(matrix[i][j]==target) return true;
        //     if(matrix[i][j]<target) i++;
        //     else j--;
        // }
        // return false;

        //Method 5 [Binary Search, Better than ladder] O(log(m+n)), O(1)
        // Here the catch is, the first element of every row is greater than last element of previous row 
        // as given in question. So we will apply binary search using it. (Striver)
        int low=0, high = (matrix.length * matrix[0].length)-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            int rowInd = mid/matrix[0].length;
            int colInd = mid%matrix[0].length;
            int ele = matrix[rowInd][colInd];
            if(ele==target) return true;
            else if(ele>target) high = mid-1;
            else low = mid+1;
        }
        return false;
        
    }
}