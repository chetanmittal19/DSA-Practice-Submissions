class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int ans = -1;
        HashMap<Character, Integer> map = new HashMap();
        for(int i=0; i<s.length(); i++){
            if(map.containsKey(s.charAt(i))) ans = Math.max(ans, i - map.get(s.charAt(i)) - 1);
            else map.put(s.charAt(i), i);
        }
        return ans;
    }
}