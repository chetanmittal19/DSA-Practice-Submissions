class Solution {
    public long subArrayRanges(int[] nums) {
        // Method 1 [Stack] O(4N), O(1)
        // we can do this by calculating sum of all largest element in subarray - sum of all minimum elements in a subarray
        // for eg1- pg[-1, -1, -1], ng[1, 2, 3], ps[-1, 0, 1], ns[3, 3, 3]
        int[] ps = previousSmaller(nums);
        int[] ns = nextSmaller(nums);
        int[] pg = previousGreater(nums);
        int[] ng = nextGreater(nums);

        long ans = 0;
        for(int i=0; i<nums.length; i++){
            ans+= nums[i] * (((long)(i-pg[i]) * (ng[i]-i)) - ((long)(i-ps[i]) * (ns[i]-i)));
        }
        return ans;
    }

    public int[] previousSmaller(int[] nums){
        int n = nums.length;
        Stack<Integer> st = new Stack<>();
        int[] arr = new int[n];

        for(int i=0; i<n; i++){
            while(!st.isEmpty() && nums[st.peek()]>nums[i]) st.pop();
            arr[i] = (st.isEmpty()) ? -1 : st.peek();
            st.push(i);
        }
        return arr;
    }

    public int[] nextSmaller(int[] nums){
        int n = nums.length;
        Stack<Integer> st = new Stack<>();
        int[] arr = new int[n];

        for(int i=n-1; i>=0; i--){
            while(!st.isEmpty() && nums[st.peek()]>=nums[i]) st.pop();
            arr[i] = (st.isEmpty()) ? n : st.peek();
            st.push(i);
        }
        return arr;
    }

    public int[] previousGreater(int[] nums){
        int n = nums.length;
        Stack<Integer> st = new Stack<>();
        int[] arr = new int[n];

        for(int i=0; i<n; i++){
            while(!st.isEmpty() && nums[st.peek()]<nums[i]) st.pop();
            arr[i] = (st.isEmpty()) ? -1 : st.peek();
            st.push(i);
        }
        return arr;
    }

    public int[] nextGreater(int[] nums){
        int n = nums.length;
        Stack<Integer> st = new Stack<>();
        int[] arr = new int[n];

        for(int i=n-1; i>=0; i--){
            while(!st.isEmpty() && nums[st.peek()]<=nums[i]) st.pop();
            arr[i] = (st.isEmpty()) ? n : st.peek();
            st.push(i);
        }
        return arr;
    }
}