class Solution {
public:
    int mod = 7 + 1e9;
    
    int countOrders(int n) {
        long long prev = 1, mul = 6, add = 9,curr = 1;
        for(int i = 2; i <= n; i++){
            curr = (prev*(mul) % mod) % mod;
            mul = (mul + add) % mod;
            add = (add + 4) % mod;
            prev = curr;
        }
        return curr % mod;
    }
};