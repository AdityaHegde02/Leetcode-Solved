class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglies(1,1);
        int i2 = 0,i3 = 0,i5 = 0;
        while(uglies.size() < n){
            int ugly = min(uglies[i2]*2,min(uglies[i3]*3,uglies[i5]*5));
            if(ugly == uglies[i2]*2){
                i2++;
            }
            if(ugly == uglies[i3]*3){
                i3++;
            }
            if(ugly == uglies[i5]*5){
                i5++;
            }
            uglies.push_back(ugly);
        }
        return uglies[n-1];
    }
};