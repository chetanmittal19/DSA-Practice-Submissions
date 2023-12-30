class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Method 1 [BruteForce] O(N^2), O(1)

        // Method 2 [Stack] O(2N), O(4N)
        // int n = heights.size();
        // stack<int> st1;
        // stack<int> st2;
        // int prevMin[n];
        // int nextMin[n];
        // for(int i=0; i<n; i++){
        //     while(!st1.empty() && heights[st1.top()]>heights[i]) st1.pop(); // for duplicacy
        //     prevMin[i] = st1.empty() ? -1 : st1.top();
        //     st1.push(i);

        //     while(!st2.empty() && heights[st2.top()]>=heights[n-i-1]) st2.pop(); // for duplicacy
        //     nextMin[n-i-1] = st2.empty() ? n : st2.top();
        //     st2.push(n-i-1);
        // }

        // int ans = 0;
        // for(int i=0; i<n; i++){
        //     int val = heights[i] * (nextMin[i] - prevMin[i] - 1);
        //     ans = max(ans, val);
        // }
        // return ans;

        // Method 3 [Stack, Striver] O(2N), O(1)
        stack<int> st;
        int maxA = 0;
        int n = heights.size();
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }
};