class Solution {
public:
    int totalMoney(int n) {
        // Method 1 [BruteForce, Iterative] O(N), O(1)

        // Method 2 [Mathematics, AP(Arithametic Progression)] O(1), O(1)
        int k = n/7;
        int sum = ((2*28 + (k-1)*7)*k)/2; //S = (n/2)(2a + (n-1)*d);

        for(int day=0; day<n%7; day++) sum+= (k+1) + day;
        return sum;
    }
};