class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i = 0;i <= num; i++){
            int num1 = i;
            int num2 = 0;
            int x = num1;
            while(x){
                num2 = num2*10 + x%10;
                x /= 10;
            }
            
            if(num1 + num2 == num){
                return true;
            }
        }
        return false;
    }
};