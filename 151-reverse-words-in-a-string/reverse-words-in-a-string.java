class Solution {
    public String reverseWords(String s) {
        int n = s.length();
        StringBuilder ans = new StringBuilder();
        int st = n-1, en = n-1;
        while(st>=0){
            while(st>=0 && s.charAt(st)==' ') st--;
            if(st==-1) break;
            en = st;
            while(st>=0 && s.charAt(st)!=' ') st--;
            ans.append(s.substring(st+1, en+1) + ' ');
        }
        ans.deleteCharAt(ans.length()-1);
        return ans.toString();

        // int n = s.length();
        // int st = n-1;
        // while(st>=0 && s.charAt(st)==' ') st--;
        // if(st==-1) return "";
        // int en = st;
        // while(st>=0){
        //     while(st>=0 && s.charAt(st)!=' ') st--;
        //     ans.append(s.substring(st+1, en+1) + " ");
        //     while(st>=0 && s.charAt(st)==' ') st--;
        //     en=st;
        // }
        
        // ans.deleteCharAt(ans.length()-1);
        // return ans.toString();
    }
}