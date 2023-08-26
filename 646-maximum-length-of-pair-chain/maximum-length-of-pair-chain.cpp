class Solution {
public:
    struct Compare {
        bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.first > b.first;
        }
    };

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int curr = INT_MIN, ans = 0;
        for(auto pair: pairs){
            if(curr<pair[0]){
                curr = pair[1];
                ans++;
            }
        }
        return ans;
    }
};