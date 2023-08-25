class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if(num.length()==0) return ans;
        // recursive(num, target, ans, "", 0, 0, 0);
        backtrack(num, target, ans, 0, "", 0, 0);
        return ans;
    }

    void backtrack(string &s, int target, vector<string> &ans, int i, const string& path, long resSoFar, long prevNum) {
        if (i == s.length()) {
            if (resSoFar == target) ans.push_back(path);
            return;
        }
        string numStr;
        long num = 0;
        for (int j = i; j < s.length(); j++) {
            if (j > i && s[i] == '0') break; // Skip leading zero number
            numStr += s[j];
            num = num * 10 + s[j] - '0';
            if (i == 0) {
                backtrack(s, target, ans, j + 1, path + numStr, num, num); // First num, pick it without adding any operator!
            } else {
                backtrack(s, target, ans, j + 1, path + "+" + numStr, resSoFar + num, num);
                backtrack(s, target, ans, j + 1, path + "-" + numStr, resSoFar - num, -num);
                backtrack(s, target, ans, j + 1, path + "*" + numStr, resSoFar - prevNum + prevNum * num, prevNum * num); // Can imagine with example: 1-2*3
            }
        }
    }

    void recursive(string &num, int target, vector<string> &ans, string s, long long val, long long prevVal, int ind){
        if(val>target) return;
        if(ind==num.length()){
            if(val==target) ans.push_back(s);
            return;
        }

        string temp ="";
        long long n = 0;
        for(int i=ind; i<num.length(); i++){
            if (i > ind && num[ind] == '0') break;
            temp+=num[i];
            n=n*10 + (num[i]-'0');
            if(ind==0) recursive(num, target, ans, temp, n, n, i+1);
            else {
                recursive(num, target, ans, s+"+"+temp, val + n, n, i+1);
                recursive(num, target, ans, s+"-"+temp, val - n, -n, i+1);
                recursive(num, target, ans, s+"*"+temp, val-prevVal + prevVal*n, prevVal*n, i+1);
            }
            // if(num[ind]=='0') break;
        }
    }
};