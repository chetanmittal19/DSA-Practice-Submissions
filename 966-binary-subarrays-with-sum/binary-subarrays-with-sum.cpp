class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> map;
        int count = 0, sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(sum==goal) count++;
            count+= map[sum-goal];
            map[sum]+=1;
        }
        return count;
    }
};