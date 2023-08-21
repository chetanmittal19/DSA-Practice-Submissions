class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        recursive(candidates, target, ans, v, 0);
        return ans;
    }

    void recursive(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &v, int i){
        if(i==candidates.size()){
            if(target==0) ans.push_back(v);

            return;
        }
        if(candidates[i]<=target){
            v.push_back(candidates[i]);
            recursive(candidates, target-candidates[i], ans, v, i);
            v.pop_back();
        }

        recursive(candidates, target, ans, v, i+1);
    }
};