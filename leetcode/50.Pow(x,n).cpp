class Solution {
public:
    double myPow(double x, long long n) {
        return n >= 0 ? quick_pow(x, abs(n)) : 1 / quick_pow(x, abs(n));
    }
private:
    double quick_pow(double x, long long n){
        double ans = 1;
        while(n>0){
            if(n & 1){
                ans *= x;
            }
            x *= x;
            n >>= 1;
        }
        return ans;
    }
};