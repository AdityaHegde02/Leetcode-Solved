class Solution {
public:
    double solve(double x, int n) {
        if(n == 0){
            return 1;
        }
        double res = 1;
        if(n % 2){
            res *= x;
        }
        
        double s = solve(x,n/2);
        return res = res*s*s;
    }
    
    double myPow(double x, int n) {
        double ans = solve(x,n);
        if(n < 0){
            return (double)1.0/ans;
        }
    
        return ans;
    }
};