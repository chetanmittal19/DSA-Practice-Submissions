class Solution {
public:
    int characterReplacement(string s, int k) {
        // Coding charms[Both method]: https://youtu.be/jXReu2CF6mI
        // Best example, s: "aabccbb", k: 2, output: 5

        // Method 1 [BruteForce, HashMap, Same logic of method 2] O(N^3), O(26) = O(1)

        // Method 2 [Sliding Window] O(2N), O(26) = O(1)
        int n=s.size(), maxLen = 0, maxFreq = 0, l=0;
        unordered_map<char, int> freq;
        for(int r=0; r<n; r++) {
            freq[s[r]]++;
            maxFreq = max(maxFreq, freq[s[r]]);
            while((r-l+1) - maxFreq > k) { // r-l+1=length of subarray, len-maxFreq > k
                freq[s[l]]--; // shrink
                l++;
            }
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};