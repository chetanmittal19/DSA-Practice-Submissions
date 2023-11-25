class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int count = 0, sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(sum==k) count++;
            count+= map[sum-k];
            map[sum]+=1;
        }
        return count;
    }
};