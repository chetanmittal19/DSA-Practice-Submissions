class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        recursive(k, n, ans, v, 1, 0);
        return ans;
    }

    void recursive(int k, int n, vector<vector<int>> &ans, vector<int> &v, int ind, int sum){
        if(sum>n) return;
        if(sum==n && k==0){
            ans.push_back(v);
            return;
        }

        for(int i=ind; i<=9; i++){
            if(i>n) break;
            v.push_back(i);
            recursive(k-1, n, ans, v, i+1, sum+i);
            v.pop_back();
        }
    }
};