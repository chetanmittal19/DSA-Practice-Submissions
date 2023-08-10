class Solution {
public:


    int calculatingFreq(vector<int> &freq){
        int maxFreq = 0;
        int minFreq = INT_MAX;
        for(int i=0; i<26; i++){
            maxFreq = max(maxFreq, freq[i]);
            if(freq[i]!=0) minFreq = min(minFreq, freq[i]);
        }
        return maxFreq-minFreq;
    }

    int beautySum(string s) {
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            vector<int> freq(26);
            for(int j=i; j<s.size(); j++){
                freq[s[j]-'a']++;
                ans+=calculatingFreq(freq);
            }
        }

        return ans;
    }
};