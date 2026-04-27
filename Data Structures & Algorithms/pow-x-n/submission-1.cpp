class Solution {
public:
 
    double myPow(double x, int n) {
        long long N = n; // avoid overflow

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return power(x, N);
    }

    double power(double x, long long n) {
        if (n == 0) return 1;

        double half = power(x, n / 2);

        if (n % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }

    //divide and conquer but computing same values again and again
    // double myPow(double x, int n) {
    //     if(n==1)
    //     {
    //         return x;
    //     }

    //     if(n%2 == 0)
    //     {
    //         int pwr = pow(x,n/2);
    //     }
    //     return pow(x,n/2)*pow(x,n-n/2);
    // }
};
