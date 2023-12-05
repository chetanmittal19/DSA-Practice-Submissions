class Solution {
public:
    int myAtoi(string s) {
        
        // Method 1 [Iterative] O(N), O(1)
        if(s.size()==0) return 0;

        int i=0;
        while(i<s.size() && s[i]==' ') i++;
        s = s.substr(i);

        int sign=1;
        if(s[0]=='-') sign = -1;
        i = (s[0]=='+' || s[0]=='-') ? 1 : 0;

        long ans=0;
        while(i<s.size()){
            if(s[i]==' ' || !isdigit(s[i])) break;
            ans = ans*10 + (s[i]-'0');
            if(sign==-1 && -1 * ans < INT_MIN) return INT_MIN;
            else if(sign==1 && ans > INT_MAX) return INT_MAX;
            i++;
        }
        return (int)(sign * ans);

        // Method 2 [Recursive] O(N), O(N)
        //removing trailing spaces first and then calling recursive function
        // int i=0, n=s.size(), sign=1;
        // while(i<s.size() && s[i]==' ') i++;
        // if(s[i]=='+') i++;
        // else if(s[i]=='-'){
        //     i++;
        //     sign=-1;
        // }
        // return recursiveAtoi(s, i, sign, 0);
    }

    int recursiveAtoi(string s, int i, int sign, long ans){
        if(sign*ans>INT_MAX) return INT_MAX;
        if(sign*ans<INT_MIN) return INT_MIN;
        if(i>=s.size() || !isdigit(s[i])) return sign*ans;
        return recursiveAtoi(s, i+1, sign, ans*10 + (s[i]-'0'));
    }
};