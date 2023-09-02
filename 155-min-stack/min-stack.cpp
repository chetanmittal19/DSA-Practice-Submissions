class MinStack {
    stack<long long> st;
    long long mini;
public:
    MinStack() {
        while(!st.empty()) st.pop();
        mini = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            mini = val;
            st.push(val);
        } else if(val<mini){
            st.push(1LL*2*val-mini);
            mini = val;
        } else st.push(val);
    }
    
    void pop() {
        if(st.empty()) return;
        long long x = st.top();
        st.pop();
        if(x<mini) mini = 2*mini*1LL - x;
    }
    
    int top() {
        if(st.empty()) return -1;
        return (st.top()<mini) ? mini : st.top();
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */