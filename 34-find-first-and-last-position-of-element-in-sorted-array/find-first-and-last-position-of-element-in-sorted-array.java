class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] ans = new int[2];
        int first = findFirst(nums, target);
        if(first==-1) return new int[]{-1, -1};

        int last = findLast(nums, target);
        ans[0] = first;
        ans[1] = last;

        return ans;
    }

    public int findFirst(int[] nums, int target){
        int low = 0, high = nums.length-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]>target){
                high = mid - 1;
            } else if(nums[mid]<target) low = mid+1;
            else{
                if(mid==0 || nums[mid]!=nums[mid-1]) return mid;
                else high = mid-1;
            }
        }
        return -1;
    }

    public int findLast(int[] nums, int target){
        int low = 0, high = nums.length-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]>target){
                high = mid - 1;
            } else if(nums[mid]<target) low = mid+1;
            else {
                if(mid==nums.length-1 || nums[mid]!=nums[mid+1]) return mid;
                else low = mid + 1;
            }
        }
        return -1;
    }
}