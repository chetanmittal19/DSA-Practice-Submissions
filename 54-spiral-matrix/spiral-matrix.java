class Solution {
    public List<Integer> spiralOrder(int[][] arr) {

        List<Integer> ans = new ArrayList<Integer>();
        int top = 0;
        int bottom = arr.length-1;
        int l = 0;
        int r = arr[0].length-1;

        while(top<=bottom && l<=r){
            for(int i=l; i<=r; i++) ans.add(arr[top][i]);
            top++;

            for(int i=top; i<=bottom; i++) ans.add(arr[i][r]);
            r--;

            if(top<=bottom){
                for(int i=r; i>=l; i--) ans.add(arr[bottom][i]);
                bottom--;
            }

            if(l<=r){
                for(int i=bottom; i>=top; i--) ans.add(arr[i][l]);
                l++;
            }
        }
        return ans;
    }
}