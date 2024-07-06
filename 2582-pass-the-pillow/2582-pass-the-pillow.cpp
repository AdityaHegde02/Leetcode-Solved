class Solution {
public:
    int passThePillow(int n, int time) {
        int ser = (time)/(n - 1);
        if(ser % 2 == 0){
            return (time % (n - 1)) + 1;
        }
        else{
            return (n - time % (n - 1));
        }
        return 0;
    }
};