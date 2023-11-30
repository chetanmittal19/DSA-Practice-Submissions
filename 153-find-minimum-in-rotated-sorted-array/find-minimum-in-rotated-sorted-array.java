class Solution {
    public int findMin(int[] nums) {
        // Method 1 [Linear Search] O(n), O(1)

        // Method 2 [Binary Search] O(logn), O(1)
        int low = 0, high = nums.length-1;
        int ans = Integer.MAX_VALUE;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[low]<=nums[high]){
                ans = Math.min(ans, nums[low]);
                break;
            }
            if(nums[low]<=nums[mid]){
                ans = Math.min(ans, nums[low]);
                low = mid+1;
            } else {
                ans = Math.min(ans, nums[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
}