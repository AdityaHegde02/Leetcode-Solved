class Solution {
public:
    bool solve(int power,int n){
        if(n <= 0 or power > 14){
            return (n == 0);
        }    
        
        return (solve(power + 1,n - pow(3,power)) || solve(power + 1,n));
    }
    
    bool checkPowersOfThree(int n) {
        return solve(0,n);
    }
};