class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> arr(n+1, 0);
        for(int i=0; i<ranges.size(); i++){
            if(ranges[i]==0) continue;
            int left = max(0, i-ranges[i]);
            arr[left] = max(arr[left], i+ranges[i]);
        }
        int end=0, farCanReach = 0, ans=0;
        //we put a condition in loop end<n which means
        for(int i=0; i<arr.size() && end<n; end = farCanReach){
            ans++;
            while(i<arr.size() && i<=end){
                farCanReach = max(farCanReach, arr[i++]);
            }
            if(end == farCanReach) return -1;
        }
        return ans;
    }
};