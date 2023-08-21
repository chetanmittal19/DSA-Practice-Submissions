class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> v = new ArrayList<>();
        recursive(nums, ans, 0, v);
        return ans;
    }

    private void recursive(int[] nums, List<List<Integer>> ans, int i, List<Integer> v) {
        if (i == nums.length) {
            ans.add(new ArrayList<>(v));
            return;
        }
        
        recursive(nums, ans, i + 1, v);
        
        v.add(nums[i]);
        recursive(nums, ans, i + 1, v);
        
        v.remove(v.size() - 1); // Backtrack by removing the last element
    }
}