class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length() <= k) return "0";
        if(k == 0) return num;

        stack<char> st;
        for(char ch: num){
            while(!st.empty() && k>0 && st.top()>ch){
                st.pop();
                k--;
            }
            st.push(ch);

            // popping preceding zeroes like in example
            if(st.size()==1 && ch=='0') st.pop();
        }

        // it means elements are in increasing order so remove from right till k!=0
        while(!st.empty() && k>0){ 
            st.pop();
            k--;
        }

        string ans = "";
        while(!st.empty()) {
            ans.push_back(st.top()); // pushing stack top to string
            st.pop(); // pop the top element
        }

        reverse(ans.begin(), ans.end());

        return (ans.size()==0) ? "0" : ans;
    }
};