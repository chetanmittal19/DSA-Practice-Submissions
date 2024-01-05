class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // Method 1 [BruteForce, TLE] O(N^2), O(1)
        // int n = nums.size();
        // int ans = 0;
        // for(int i=0; i<n; i++){
        //     int count = 0;
        //     for(int j=i; j<n; j++){
        //         count+=nums[j]%2;
        //         if(count==k) ans++;
        //         else if(count>k) break;
        //     }
        // }
        // return ans;

        // Method 2
        int n = nums.size();
        for(int i=0; i<n; i++) nums[i] = nums[i]%2;
        unordered_map<int, int> map;
        int ans = 0, sum = 0;
        for(int r=0; r<n; r++){
            sum+=nums[r];
            if(sum==k) ans++;
            ans+= map[sum-k];
            map[sum]++;
        }
        return ans;
    }
};