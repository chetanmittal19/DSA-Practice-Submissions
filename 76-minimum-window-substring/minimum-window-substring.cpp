class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        int count = 0, len = INT_MAX;
        int startIndex = -1;
        int i=0, j=0;

        for(auto ch: t) m1[ch]++;
        while(j<m){
            m2[s[j]]++;
            if(m2[s[j]]<=m1[s[j]]) count++;
            if(count==n) {
                while(m2[s[i]]>m1[s[i]]) {
                    if(m2[s[i]]>m1[s[i]]) m2[s[i]]--;
                    i++;
                }

                if(len>j-i+1) {
                    len = j-i+1;
                    startIndex = i;
                }
            }
            j++;
        }
        return (startIndex==-1) ? "" : s.substr(startIndex, len);
    }
};