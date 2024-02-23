class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // Method 1 [LinearSearch, Bruteforce, TLE] O((sum-max)*n), O(1)
        // int n = nums.size();
        // if(k>n) return -1;
        // int low = *max_element(nums.begin(), nums.end());
        // int high = accumulate(nums.begin(), nums.end(), 0); //calculates sum of all elements
        // for(int maxSum=low; maxSum<=high; maxSum++){
        //     int cnt = calculateSubarrays(nums, maxSum);
        //     if(cnt == k) return maxSum;
        // }
        // return low;

        // Method 2 [BinarySearch] O(log(sum-max) * n), O(1)
        int n = nums.size();
        if(k>n) return -1;
        int l = *max_element(nums.begin(), nums.end());
        int h = accumulate(nums.begin(), nums.end(), 0);
        int ans = l;
        while(l<=h) {
            int mid = l+(h-l)/2;
            if(calculateSubarrays(nums, mid)>k) l=mid+1;
            else {
                ans = mid;
                h = mid-1;
            }
        }
        return ans;
    }

    int calculateSubarrays(vector<int> &nums, int maxSum){
        int count=1;
        long long sum=0;
        for(auto i: nums) {
            // if(i>maxSum) return false;
            sum+=i;
            if(sum>maxSum) {
                count++;
                sum=i;
            }
        }
        return count;
    }
};