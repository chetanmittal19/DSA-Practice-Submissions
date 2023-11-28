class Solution {
    public List<Integer> majorityElement(int[] nums) {
        //Method 1 [Brute Force] O(N^2), O(1) -> ignoring the answer space

        //Method 2 [HashMap] O(2N), O(N) -> ignoring the answer space
        // traverse the array and store elements with their count into map and then traverse the map and then add those elements into the list which has count > n/3

        //Method 3 [HashMap] O(N), O(N) -> ignoring the answer space
        // It will only take one iteration instead of 2 iterations in previous method
        // int minValue = (nums.length/3) + 1;
        // HashMap<Integer, Integer> map = new HashMap<>();
        // List<Integer> ans = new ArrayList<>();

        // for(int i=0; i<nums.length; i++){
        //     map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
        //     if(map.get(nums[i])==minValue) ans.add(nums[i]);
        // }
        // return ans;

        //Method 4 
        int cnt1=0, cnt2=0;
        int ele1 = Integer.MIN_VALUE, ele2 = Integer.MIN_VALUE;
        for(int i=0; i<nums.length; i++){
            if(cnt1==0 && nums[i]!=ele2){
                cnt1 = 1;
                ele1 = nums[i];
            } else if(cnt2==0 && nums[i]!=ele1){
                cnt2 = 1;
                ele2 = nums[i];
            } else if(nums[i]==ele1) cnt1++;
            else if(nums[i]==ele2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }

        List<Integer> ans = new ArrayList<>();
        cnt1=0; 
        cnt2=0;
        for(int i=0; i<nums.length; i++){
            if(nums[i]==ele1) cnt1++;
            if(nums[i]==ele2) cnt2++;
        }

        int minValue = (nums.length/3)+1;
        if(cnt1>=minValue) ans.add(ele1);
        if(cnt2>=minValue) ans.add(ele2);
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