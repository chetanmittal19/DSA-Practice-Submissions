class Solution {
public:
    double myPow(double x, int n) {
        //Method 1 [Iterative]
        double ans = 1.0;
        long long nn = n;
        if(nn<0) nn*=-1;
        while(nn>0){
            if(nn%2==1) ans*=x;
            x*=x;
            nn/=2;
        }
        if(n<0) ans=(double)(1.0)/(double)(ans);
        return ans;

        //Method 2 [Recursive]
        // if(n==0) return 1;
        
        // double ans = myPow(x, n/2);
        // ans*=ans;
        // if(n%2==1) ans*=x;
        // return ans;
    }
};