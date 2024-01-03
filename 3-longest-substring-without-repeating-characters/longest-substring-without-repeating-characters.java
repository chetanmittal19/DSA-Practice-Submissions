class Solution {
    public int lengthOfLongestSubstring(String s) {
        // Method 1 [BruteForce] O(N^3), O(1)

        // Method 2 [Better] O(N^2), O(N)

        // Method 3 [Optimised, STRIVER] O(2N), O(N)
        if(s.length()==0) return 0;
        int maxans = Integer.MIN_VALUE;
        Set <Character> set = new HashSet < > ();
        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            char ch = s.charAt(r);
            while (l < r && set.contains(ch)) set.remove(s.charAt(l++));
            set.add(ch);
            maxans = Math.max(maxans, r - l + 1);
        }
        return maxans;

        // Method 4 [HashMap, STRIVER] O(N), O(N)
        // int n = s.length();
        // HashMap<Character, Integer> map = new HashMap<>();
        // int left = 0, right = 0, maxLen = 0;
        // while(right<n) {
        //     char ch = s.charAt(right);
        //     if(map.containsKey(ch)) left = Math.max(left, map.get(ch)+1);
        //     map.put(ch, right);
        //     maxLen = Math.max(maxLen, right-left+1);
        //     right++;
        // }
        // return maxLen;
    }
}