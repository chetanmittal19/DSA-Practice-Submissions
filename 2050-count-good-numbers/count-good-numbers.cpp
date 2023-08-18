#define mod 1000000007
class Solution {
public:
    long long power(long long x, long long y){
        if(y==0) return 1;
        long long ans = power(x, y/2);
        ans*=ans;
        ans=ans%mod;
        if(y%2) ans*=x; //y%2 means if y is even then y%2 is 0 ans 0 means false so it will not execute
        ans%=mod;
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = n/2 + n%2;
        return (power(4, odd) * power(5, even))%mod;
    }
};