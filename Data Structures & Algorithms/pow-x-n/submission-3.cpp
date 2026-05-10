class Solution {
public:
    double fastPow(double x, int n){
        if (n == 0) return 1;
        double half = fastPow(x, n/2); 
        if (n % 2 == 1) {
            return half * half * x;
        }

        return half * half;
    }
    double myPow(double x, int n) {
        // Method: Recursion
        // preprocess: n < 0 -> x = 1/x
        if (n < 0){
            x = 1/x;
            n = -n;
        }
        return fastPow(x, n);
    }
};
