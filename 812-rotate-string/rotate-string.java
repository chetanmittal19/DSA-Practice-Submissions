class Solution {
    public boolean rotateString(String s, String goal) {
        // Method 1 O(N^2), O(1)
        // Step-1 return false if length of both are not equal
        // Step-2 rotate each char one by one of 's' and return true if it is equal to 't'

        // Method 2 O(N), O(1)
        if(s.length()!=goal.length()) return false;

        String newString = s+s;
        return newString.indexOf(goal)!=-1;
    }
}