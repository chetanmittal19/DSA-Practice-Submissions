class Solution {
public:

    void recursive(string digits, vector<string> &ans, string hash[], int count, string s){
        if(count==digits.size()){
            ans.push_back(s);
            return;
        }

        string chcode = hash[digits[count]-'2'];
        for(int i=0; i<chcode.size(); i++){
            recursive(digits, ans, hash, count+1, s+chcode[i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0) return ans;

        string hash[]  = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        recursive(digits, ans, hash, 0, "");
        return ans;
    }
};