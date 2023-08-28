class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        int i=0;
        while(start>0 || goal>0){
            ans+=(1&start) ^ (1&goal);
            start>>=1;
            goal>>=1;
        }
        return ans;
    }
};