class Solution {
    public int minDays(int[] arr, int m, int k) {
        int n = arr.length;
        if((n/k) < m) return -1;

        int low = 1;
        int high = Arrays.stream(arr).max().getAsInt();
        int ans = Integer.MAX_VALUE;

        while(low<=high){
            int mid = low + (high - low)/2;
            int c = calculateBouquets(arr, mid, k);
            if(c>=m){
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }

    int calculateBouquets(int[] arr, int mid, int k){
        int count = 0;
        int adj = 0;
        for(int i: arr){
            if(i<=mid) adj++;
            else adj = 0;

            if(adj==k) {
                adj = 0;
                count++;
            }
        }
        return count;
    }
}