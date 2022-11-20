class Solution {
public:
    int smallestRepunitDivByK(int k) {
        vector<int> rems = {1};
        for(int i = 0; i < 50000; i++){
            rems.push_back((rems[i]*10 + 1) % k);
        }
        for(int i = 0; i <= 50000; i++){
            if(rems[i] % k == 0){
                return i + 1;
            }
        }
        return -1;
    }
};