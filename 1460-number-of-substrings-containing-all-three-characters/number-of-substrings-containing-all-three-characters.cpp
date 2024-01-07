class Solution {
public:
    int numberOfSubstrings(string s) {
        // Method 1 [BruteForce, TLE] O(N^2), O(1)
        // We can use three variables for a,b,c but code will be clumsy. Max length of set is 3(const.)
        // int n = s.size(), ans = 0;
        // for(int i=0; i<n; i++){
        //     unordered_set<char> set;
        //     for(int j=i; j<n; j++){
        //         set.insert(s[j]);
        //         if(set.size()==3) ans++;
        //     }
        // }
        // return ans;

        // Method 2 [Sliding Window, Let's leet]
        // link: https://youtu.be/aM6rquHd62Y
        int l=0, r=0, n=s.size(), ans=0;
        unordered_map<char, int> map;
        while(r<n) {
            map[s[r]]++;
            while(map['a'] && map['b'] && map['c']) { // if map['a']>=1 true else false
                ans+=n-r;
                map[s[l]]--;
                l++;
            }
            r++;
        }
        return ans;
    }
};