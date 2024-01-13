class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Method 1 [Sorting] O(nlogn), O(n)

        // Method 2 [Binary Search] O(n * log(max-min)), O(1)
        // We first calculate the lowest and highest element in the array to get the range
        // After that we apply binary search in that range and check if how many elements are less than middle elements... and move the lower and higher accordingly.

        // Method 3 [Heap / Priority Queue] O(nlogk), O(k)
        priority_queue<int> p; // max priority queue
        for(int i: nums) p.push(i);
        for(int i=0; i<k-1; i++) p.pop();
        return p.top();
    }
};