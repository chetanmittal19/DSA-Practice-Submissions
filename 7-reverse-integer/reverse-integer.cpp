class Solution {
public:
    int reverse(int x) {
        long long num = 0;  // Use long long to handle potential overflow
        while (x != 0) {
            num *= 10;
            num += x % 10;
            x /= 10;
        }
        
        if (num < INT_MIN || num > INT_MAX) {
            return 0;
        }

        return int(num);
    }
};