class Solution {
public:
    int countDigits(int num) {
        int n = num, ans = 0;
        while(num != 0){
            int r = num % 10;
            if(n % r == 0){
                ans++;
            }
            num /= 10;
        }
        return ans;
    }
};