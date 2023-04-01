class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0){
            return 1;
        }
        else if(n == 1){
            return 10;
        }
        int ans = 10;
        for(int i = 2; i <= n; i++){
            long long int temp = 9;
            for(int j = 0; j < i - 1; j++){
                temp *= (9 - j);
            }
            ans += temp;
        }
        return ans;
    }
};