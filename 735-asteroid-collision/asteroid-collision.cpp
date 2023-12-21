class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for(auto val: asteroids) {
            if(val > 0) st.push(val);
            else {
                // popping values which are less than val in the stack
                while(!st.empty() && st.top()>0 && st.top() < -val) st.pop();
                if(!st.empty() && st.top() == -val) st.pop(); // if val and top value is equal
                else if(!st.empty() && st.top() > -val){} // if stack top is greater than val
                else st.push(val);
            }
        }
        
        vector<int> ans(st.size());
        int i=st.size()-1;
        while(!st.empty()){
            ans[i--] = st.top();
            st.pop();
        }
        return ans;
    }
};