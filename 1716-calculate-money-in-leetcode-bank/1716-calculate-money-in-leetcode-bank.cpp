class Solution {
public:
    int totalMoney(int n) {
        int start = 1, money = 0;
        while(true){
            for(int i = start; n > 0 and i < start + 7; i++){
                money += i;
                n--;
            }
            if(n > 0){
                start++;
            }
            else{
                break;
            }
        }
        return money;
    }
};