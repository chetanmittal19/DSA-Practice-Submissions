class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0; i<(1<<n); i++){ // alternate pow(2, n);
            vector<int> v;
            for(int j=0; j<n; j++){
                if((1<<j) & i) v.push_back(nums[j]); //alternate- ((1<<j) & i) !=0 in if condn
            }
            ans.push_back(v);
        }
        return ans;
    }
};