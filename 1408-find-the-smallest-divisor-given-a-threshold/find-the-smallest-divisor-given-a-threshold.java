class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        int low = 1;
        int high = Arrays.stream(nums).max().getAsInt();
        int ans = 0;

        while(low<=high){
            int mid = low + (high - low)/2;
            int count = 0;
            for(int i=0; i<nums.length; i++){
                count+= Math.ceil((double)nums[i]/mid);
            }

            if(count<=threshold){
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }
}