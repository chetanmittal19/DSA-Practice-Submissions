class Solution {
public:
    string reverseWords(string s) {
        // string ans;
        // int n = s.length();
        // int st = n-1;
        // while(st>=0 && s[st]==' ') st--;
        // if(st==-1) return "";
        // int en = st;
        // while(st>=0){
        //     while(st>=0 && s[st]!=' ') st--;
        //     ans+= s.substr(st+1, en-st) + " ";
        //     while(st>=0 && s[st]==' ') st--;
        //     en=st;
        // }
        // ans.erase(ans.length()-1);
        // return ans;

        int n = s.size();
        string ans;
        int st = n-1, en = n-1;
        while(st>=0){
            while(st>=0 && s[st]==' ') st--;
            if(st==-1) break;
            en = st;
            while(st>=0 && s[st]!=' ') st--;
            ans+= s.substr(st+1, en-st) + ' '; //en+1-(st+1) = en-st
        }
        ans.pop_back();
        return ans;
    }
};