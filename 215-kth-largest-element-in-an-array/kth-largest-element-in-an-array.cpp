class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==1) return nums[0];
        priority_queue<int> p;
        for(int i: nums) p.push(i);

        for(int i=1; i<=k; i++){
            if(i==k) return p.top();
            p.pop();
        }
        return -1;
    }
};