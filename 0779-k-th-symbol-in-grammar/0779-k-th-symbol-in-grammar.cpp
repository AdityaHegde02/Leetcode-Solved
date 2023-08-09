class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1){
            return 0;
        }
        if(n == 2){
            return (k == 1)?0:1;
        }
        
        int len = pow(2,n - 1);
        if(k <= (len/2)){
            return kthGrammar(n - 1,k);
        }
        return !kthGrammar(n - 1,k - len/2);
    }
};