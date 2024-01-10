class Solution {
public:
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        // Method 1 [BruteForce] O(N^2), O(1)

        // Method 2 [Sliding Window, Code With Alisha] O(2N), O(1)
        return atMost(arr, k) - atMost(arr, k-1);
    }

    int atMost(vector<int>& arr, int k) {
        int n = arr.size(), l=0, ans=0;
        unordered_map<int, int> freq;
        for(int r=0; r<n; r++) {
            freq[arr[r]]++;
            while(freq.size()>k) {
                freq[arr[l]]--;
                if(freq[arr[l]]==0) freq.erase(arr[l]);
                l++;
            }
            ans+=r-l+1;
        }
        return ans;
    }
};