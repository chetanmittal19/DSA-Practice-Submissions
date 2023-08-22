class Solution {
public:
    double myPow(double x, int n) {
        //Method 1 [Same method as method 2 but using bit operators] O(NlogN), O(1)
        double ans = 1.0;
        long long nn = n;
        if(nn<0) nn*=-1;
        while(nn>0){
            if(nn&1) ans*=x;
            x*=x;
            nn>>=1;
        }
        if(n<0) ans=(double)(1.0)/(double)(ans);
        return ans;

        //Method 2 [Iterative] O(logN), O(1) where N is no. of bits in 'n'
        // double ans = 1.0;
        // long long nn = n;
        // if(nn<0) nn*=-1;
        // while(nn>0){
        //     if(nn%2==1) ans*=x;
        //     x*=x;
        //     nn/=2;
        // }
        // if(n<0) ans=(double)(1.0)/(double)(ans);
        // return ans;

        //Method 3 [Recursive] O(logN), O(N)
        // return recursive(x, 1L * n);
    }

    double recursive(double x, long n){ //here we changed the datatype of n to long to prevent integer overflow
        if(n==0) return 1;
        if(n<0) return recursive(1/x, -n);
        return (n % 2 == 0) ? recursive(x*x, n/2) : x * recursive(x*x, n/2);
    }
};