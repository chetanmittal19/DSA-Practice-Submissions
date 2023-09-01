class Solution {
public:
    vector<int> countBits(int n) {
        //Method 1 O(N+1), O(1) -> ignoring the space for the answer
        vector<int> ans(n+1, 0);
        for(int i=1; i<=n; i++){
            ans[i] = (i&1) + ans[i/2];
        }
        return ans;
    }
};