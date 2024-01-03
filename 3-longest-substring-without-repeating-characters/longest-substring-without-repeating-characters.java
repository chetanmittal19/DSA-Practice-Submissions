class Solution {
    public int lengthOfLongestSubstring(String s) {
        // Method 1 [BruteForce] O(N^3), O(1)

        // Method 2 [Optimised] O(N^2), O(N)

        // Method 3 []

        // Method 2 [HashMap]
        int n = s.length();
        HashMap<Character, Integer> map = new HashMap<>();
        int left = 0, right = 0, maxLen = 0;
        while(right<n) {
            char ch = s.charAt(right);
            if(map.containsKey(ch)) left = Math.max(left, map.get(ch)+1);
            map.put(ch, right);
            maxLen = Math.max(maxLen, right-left+1);
            right++;
        }
        return maxLen;
    }
}