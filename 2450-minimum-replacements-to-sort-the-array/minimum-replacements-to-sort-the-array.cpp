class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        // [1, 2, 9, 11, 3, 4]
        long long res = 0;
        int n = nums.size();
        long long maxMinValue = nums[n-1];
        for(int i=n-2; i>=0; i--){
            long long parts = ceil(nums[i]/(double)maxMinValue);
            res+= parts-1;
            maxMinValue = nums[i]/parts;
        }
        return res;
    }
};