class Solution {
    public List<Integer> majorityElement(int[] nums) {
        //Method 1 [Brute Force] O(N^2), O(1) -> ignoring the answer space

        //Method 2 [HashMap] O(2N), O(N) -> ignoring the answer space
        // traverse the array and store elements with their count into map and then traverse the map and then add those elements into the list which has count > n/3

        //Method 3 [HashMap] O(N), O(N) -> ignoring the answer space
        int minValue = (nums.length/3) + 1;
        HashMap<Integer, Integer> map = new HashMap<>();
        List<Integer> ans = new ArrayList<>();

        for(int i=0; i<nums.length; i++){
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
            if(map.get(nums[i])==minValue) ans.add(nums[i]);
        }
        return ans;


        //Method 4
        // int n = nums.length;
        // if(n==1) return Arrays.asList(nums[0]);
        // if(n==2){
        //     if(nums[0]!=nums[1]) return Arrays.asList(nums[0], nums[1]);
        //     else return Arrays.asList(nums[0]);
        // }

        // Arrays.sort(nums);
        // List<Integer> ans = new ArrayList<>();
        // int count = 1;
        // for(int i=1; i<n; i++){
        //     if(nums[i]==nums[i-1]) count++;
        //     else {
        //         if(count>n/3) ans.add(nums[i-1]);
        //         count=1;
        //     }
        // }

        // if(count>n/3) ans.add(nums[n-1]);
        // return ans;
    }
}