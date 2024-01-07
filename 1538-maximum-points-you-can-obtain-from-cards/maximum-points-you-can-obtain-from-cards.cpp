class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int l=0, r=0, ans=0, wSum = 0; // window sum
        while(r<n-k) wSum+=cardPoints[r++];
        while(r<n) {
            ans=max(ans, sum-wSum);
            wSum = wSum + cardPoints[r++]-cardPoints[l++];
        }
        ans=max(ans, sum-wSum);
        return ans;
    }
};