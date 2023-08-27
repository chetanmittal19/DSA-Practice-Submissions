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
        if(k==0){
            if(sum==n) ans.push_back(v);
            return;
        }

        for(int i=ind; i<=9; i++){
            if(i>n) break; // without this also code will work, but if the n is smaller that is between (1 to 9) it will save lot of recursive calls
            v.push_back(i);
            recursive(k-1, n, ans, v, i+1, sum+i);
            v.pop_back();
        }
    }
};