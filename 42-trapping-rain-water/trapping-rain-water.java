class Solution {
    public int trap(int[] height) {
        // Method 1 [BruteForce] O(N^2), O(1)
        // At each point find the leftmax and rightmax such that waterTrapped += min(leftMax, rightmax) - arr[i]

        // Method 2 [Better] O(3N), O(2N)
        // use two arrays one two store current max from left to right and other to store current max from right to left

        // Method 3 [Two Pointer, Code with Alisha] O(N), O(1)
        int left = 0, right = height.length-1, lmax = 0, rmax = 0, water = 0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=lmax) lmax = height[left];
                else water+= lmax - height[left];
                left++;
            } else {
                if(height[right]>=rmax) rmax = height[right];
                else water+= rmax - height[right];
                right--;
            }
        }
        return water;
    }
}