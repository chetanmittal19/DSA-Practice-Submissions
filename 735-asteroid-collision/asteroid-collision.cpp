class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for(int i=0; i<n; i++){
            if(st.empty() || st.top()<0 || asteroids[i]>0) st.push(asteroids[i]);
            else {
                int ele = asteroids[i];
                bool flag = false;
                while(!st.empty() && st.top()>0 && ele<0){
                    if(st.top()==abs(ele)){
                        st.pop();
                        flag = true;
                        break;
                    } else {
                        if(abs(ele)<st.top()) ele = st.top();
                        st.pop();
                    }
                }
                if(!flag) st.push(ele);
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