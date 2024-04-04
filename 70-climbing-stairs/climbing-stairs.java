class Solution {
    public int climbStairs(int n) {
        // Method 1 [Recusrive, TLE]
        // if(n<=0) return 0;
        // int ans = 0;
        // if(n-1>=0) ans+=climbStairs(n-1);
        // if(n-2>=0) ans+=climbStairs(n-2);
        // return ans;

        // Method 2 [Tabulation] O(n), O(n) 
        // if(n<0) return 0;
        // if(n<=1) return n;
        // int[] dp = new int[n + 1];
        // dp[0] = 1;
        // dp[1] = 1;
        // for(int i=2; i<=n; i++) {
        //     dp[i] = dp[i-1] + dp[i-2];
        // }
        // return dp[n];

        // Method 3 [Memoisation] O()
        if(n<=0) return 0;
        int[] dp = new int[n+1];
        Arrays.fill(dp, -1);
        dp[0] = dp[1] = 1;
        calculateWays(dp, n);
        return dp[n];
    }

    private int calculateWays(int[] dp, int n) {
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        dp[n] = calculateWays(dp, n-1) + calculateWays(dp, n-2);
        return dp[n];
    }
}