class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        recursive(nums, ans, v, 0);
        return ans;

    }

    void recursive(vector<int> &nums, vector<vector<int>> &ans, vector<int> &v, int ind){
        ans.push_back(v);
        for(int i=ind; i<nums.size(); i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            v.push_back(nums[i]);
            recursive(nums, ans, v, i+1);
            v.pop_back();
        }
    }
};