class Solution {
public:
    int jump(vector<int>& nums) {
        // Method 1 [Recursion] O(2^N), O(N)
        // return solve(nums, 0);

        // Method 2 [Greedy] O(N), O(1)
        int current=0, jumps=0, farthest=0;
        for(int i=0; i<nums.size()-1; i++) {
            farthest = max(farthest, i+nums[i]);
            if(i==current) {
                current = farthest;
                jumps++;
            }
        }
        return jumps;
    }

    // int solve(vector<int>& nums, int ind) {
    //     if(ind>=nums.size()-1) return 0;
    //     int ans = INT_MAX;
    //     for(int i=1; i<=nums[ind]; i++) {
    //         int res = solve(nums, ind+i);
    //         if(res!=INT_MAX) ans = min(ans, 1+res);
    //     }
    //     return ans;
    // }
};