class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        //Method 1 [Hashset, Similar to 3 sum method-1] O(N^4), O(2*no. of set)
        if(nums.length<4) return new ArrayList<>();
        int n = nums.length;
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();

        for(int i=0; i<n-3; i++){
            // if(i>0 && nums[i]==nums[i-1]){
            //     continue;
            // }
            for(int j=i+1; j<n-2; j++){
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                int k=j+1, l=n-1;
                while(k<l){
                    long sum = (long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum<target) k++;
                    else if(sum>target) l--;
                    else {
                        res.add(Arrays.asList(nums[i], nums[j], nums[k], nums[l]));
                        int t1 = k, t2 = l;
                        while(k<l && nums[k]==nums[t1]) k++;
                        while(k<l && nums[l]==nums[t2]) l--;
                    }
                }
            }
            while (i + 1 < n && nums[i] == nums[i + 1]) i++;
        }
        return res;
    }
}