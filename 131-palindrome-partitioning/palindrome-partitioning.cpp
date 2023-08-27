class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Method 1 [Recursion and Backtracking]
        //Time = 2^n(For finding all the possible partitions) * n (to check for palindrome) * k(for storing vectors)
        //Space = n(recursion stack) + n^2 (for storing answer)
        vector<vector<string>> ans;
        vector<string> v;
        recursive(s, ans, v, 0);
        return ans;
    }

    void recursive(string s, vector<vector<string>> &ans, vector<string> &v, int ind){
        if(ind==s.size()){
            ans.push_back(v);
            return;
        }

        for(int i=ind; i<s.size(); i++){
            if(isPalindrome(s, ind, i)){
                v.push_back(s.substr(ind, i-ind+1));
                recursive(s, ans, v, i+1);
                v.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int st, int en){ //adding & makes it more faster
        while(st<en){
            if(s[st]!=s[en]) return false;
            st++;
            en--;
        }
        return true;
    }
};