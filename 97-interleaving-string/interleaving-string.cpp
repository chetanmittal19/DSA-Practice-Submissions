class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        //Method 1 [Recursion, TLE] O(2^(m+n)), O(m+n) 
        // we will generate all the possible combination of s1, s2 which can be formed 
        // if(s1.length() + s2.length()!=s3.length()) return false;
        // return recursive(s1, 0, s2, 0, "", s3);

        //Method 2 [DP]
        int m = s1.length();
        int n = s2.length();
        
        if (m + n != s3.length()) return false;
        
        // Create a 2D DP array dp, where dp[i][j] represents whether the first i characters of s1 and the first j characters of s2 can interleave to form the first i+j characters of s3.
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Base case: empty strings can interleave to form an empty string
        dp[0][0] = true;
        
        // Fill in the DP array
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i > 0 && s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                }
                if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }
        
        return dp[m][n];
    }

    bool recursive(string &s1, int i, string &s2, int j, string res, string &s3){
        if(i==s1.length() && j==s2.length() && res==s3) return true;
        if(i<s1.length() && recursive(s1, i+1, s2, j, res+s1[i], s3)) return true;
        if(j<s2.length() && recursive(s1, i, s2, j+1, res+s2[j], s3)) return true;
        return false;
    }
};