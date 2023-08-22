// #include<vector>

class Solution {
public:

    void recursive(string digits, vector<string> &ans, map<char,string> &hash, int count, string s){
        if(count==digits.size()){
            ans.push_back(s);
            return;
        }

        string chcode = hash[digits[count]];
        for(int i=0; i<chcode.size(); i++){
            recursive(digits, ans, hash, count+1, s+chcode[i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0) return ans;

        // string hash[]  = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        map<char, string> hash;
        hash['2'] = "abc";
        hash['3'] = "def";
        hash['4'] = "ghi";
        hash['5'] = "jkl";
        hash['6'] = "mno";
        hash['7'] = "pqrs";
        hash['8'] = "tuv";
        hash['9'] = "wxyz";
        recursive(digits, ans, hash, 0, "");
        return ans;
    }
};