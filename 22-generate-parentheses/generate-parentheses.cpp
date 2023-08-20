class Solution {
public:

    void generate(vector<string> &ans, int n, int open, int closed, string s){
        // if(open>n || closed>open) return;
        if(2*n==s.size()) {
            ans.push_back(s);
            return;
        }
        if(open<n) generate(ans, n, open+1, closed, s+"(");
        if(closed<open) generate(ans, n, open, closed+1, s+")");
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(ans, n, 0, 0, "");
        return ans;
    }
};