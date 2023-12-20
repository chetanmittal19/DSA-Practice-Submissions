class Solution {
    public int[] nextGreaterElements(int[] nums) {
        // Eg- [3, 8, 4, 1, 2] ouput: [8, -1, 8, 2, 3]
        // Method 1 [BruteForce] O(N^2), O(N)

        // Method 2 [Optimised] O(2N), O(N)
        int n = nums.length;
        Stack<Integer> st = new Stack<>();
        for(int i=n-2; i>=0; i--){
            while(!st.isEmpty() && st.peek()<=nums[i]) st.pop();
            st.push(nums[i]);
        }

        int[] ans = new int[n];
        for(int i=n-1; i>=0; i--){
            while(!st.isEmpty() && st.peek()<=nums[i]) st.pop();
            if(st.isEmpty()) ans[i] = -1;
            else ans[i] = st.peek();
            st.push(nums[i]);
        }
        return ans;
    }
}