class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st1;
        stack<int> st2;
        int prevMin[n];
        int nextMin[n];
        for(int i=0; i<n; i++){
            while(!st1.empty() && heights[st1.top()]>heights[i]) st1.pop(); // for duplicacy
            prevMin[i] = st1.empty() ? -1 : st1.top();
            st1.push(i);

            while(!st2.empty() && heights[st2.top()]>=heights[n-i-1]) st2.pop(); // for duplicacy
            nextMin[n-i-1] = st2.empty() ? n : st2.top();
            st2.push(n-i-1);
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            int val = heights[i] * (nextMin[i] - prevMin[i] - 1);
            ans = max(ans, val);
        }

        return ans;
    }
};