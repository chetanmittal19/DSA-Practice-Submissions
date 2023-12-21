class Solution {
    public int sumSubarrayMins(int[] arr) {
        // Method 1 [BruteForce] O(N^3), O(1)

        // Method 2 [Better] O(N^2), O(1) 
        // we can calculate smallest in a window while creating a window

        // Method 3 [Stack, Fraz] O(3N), O(2N)
        // for eg2: prevSmall = [-1, 0, 1, 0, -1], nextSmall = [4, 3, 3, 4, 5]
        int n = arr.length;
        Stack<Integer> st1 = new Stack<>();
        Stack<Integer> st2 = new Stack<>();
        int[] prevSmall = new int[n];
        int[] nextSmall = new int[n];

        for(int i=0; i<n; i++) {
            while(!st1.isEmpty() && arr[st1.peek()]>=arr[i]) st1.pop();
            if(st1.isEmpty()) prevSmall[i] = -1;
            else prevSmall[i] = st1.peek();
            st1.push(i);
        }

        for(int i=n-1; i>=0; i--) {
            while(!st2.isEmpty() && arr[st2.peek()]>arr[i]) st2.pop();
            if(st2.isEmpty()) nextSmall[i] = n;
            else nextSmall[i] = st2.peek();
            st2.push(i);
        }

        long ans = 0;
        for(int i=0; i<n; i++){
            ans = (ans + (long)((long)arr[i] * (i - prevSmall[i]) * (nextSmall[i] - i)))%1000000007;
            // ans%= 1000000007;
        }
        return (int)ans;
    }
}