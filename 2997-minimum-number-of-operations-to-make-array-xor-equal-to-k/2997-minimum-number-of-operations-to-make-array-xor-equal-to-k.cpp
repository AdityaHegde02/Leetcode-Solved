class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ops = 0;
        for(int i = 0; i < 32; i++){            // bit
            int need = ((k >> i) & 1), odds = 0;
            for(auto &j : nums){
                odds += ((j >> i) & 1);
            }
            if(odds % 2){
                ops += (!need);
            }
            else{
                ops += need;
            }
        }
        return ops;
    }
};