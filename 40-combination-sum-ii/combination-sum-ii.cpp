class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        // Method 1 [HashSet]
        // we do combination sum 1 by using unordered_set<vector<int>>
        // time: O(2^target * k * logN) because we will be storing vector of length k into set and storing in a set takes logN time where N is size of the set

        //Method 2 
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> v;
        recursive(arr, target, ans, v, 0);
        return ans;
    }

    void recursive(vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> &v, int ind){
        if(target==0){
            ans.push_back(v);
            return;
        }

        for(int i=ind; i<arr.size(); i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            v.push_back(arr[i]);
            recursive(arr, target-arr[i], ans, v, i+1);
            v.pop_back();
        }
    }
};