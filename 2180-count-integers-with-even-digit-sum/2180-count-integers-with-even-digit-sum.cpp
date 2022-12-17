class Solution {
public:
    int countEven(int num) {
        int ans = 0;
        for(int i = 1; i <= num; i++){
            int sum = 0;
            int j = i;
            while(j != 0){
                sum += (j % 10);
                j /= 10;
            }
            if(sum % 2 == 0){
                ans++;
            }
        }
        return ans;
    }
};