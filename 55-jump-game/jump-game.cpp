class Solution {
public:
    bool canJump(vector<int>& nums) {
        // // Method 1 [Recursion] O(N^2), O(N)
        // if(nums.size()==0) return true;
        // return func(nums, 0);

        // Method 2 [DP-Memoisation] O(N^2), O(N)

        // Method 3 [DP-Tabulation] O(N^2), O(N)

        // Method 4 [Greedy] O(N), O(1)
        // This approach is a greedy algorithm. It iterates through the array, updating the maximum reachable position (maxReach). It checks whether the current position is within the maximum reachable range. If it is, the algorithm continues. If the maximum reachable position is greater than or equal to the last index, it returns true; otherwise, it returns false.
        int n = nums.size();
        int maxReach = 0;
        for(int i=0; i<n && i<=maxReach; i++) {
            maxReach = max(maxReach, i+nums[i]);
            if(maxReach>=n-1) return true;
        }
        return false;
    }

    // bool func(vector<int>& nums, int ind) {
    //     if(ind>=nums.size()-1) return true;
    //     for(int i=1; i<=nums[ind]; i++) {
    //         if(func(nums, ind+i)) return true;
    //     }
    //     return false;
    // }
};